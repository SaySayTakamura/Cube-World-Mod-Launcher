#include "ModWidget.h"
#include <iostream>
#include <fstream>
#include <process.h>

static std::string file_name = "mods-settings.cwb";
static const int MODS_PER_PAGE = 7;
void* VTABLE[43];

mod::ModWidget* mod::ModWidget::ctor(cube::Game* game, plasma::Node* node, plasma::Node* background, std::vector<DLL*>* mods)
{
	// Construct basewidget
	std::wstring wstr_empty(L"");
	((cube::BaseWidget*)this)->ctor(game->plasma_engine, node, &wstr_empty);

	// Set fields
	this->game = game;
	this->hover_state = 0;
	this->background = background;
	this->mods = mods;
	this->scroll_value = 0;
	this->max_height = 0;
	this->changed = false;

	// Set scalable font
	std::wstring fontName(L"resource1.dat");
	this->SetScalableFont(&fontName);
	this->Translate(100, 200, 1);

	// Toggle mod button
	void(*mod_toggle)(uint64_t) = ModTogglePressed;
	std::wstring wstr_node_name(L"mod-toggle-node");
	std::wstring wstr_node_text(L"");
	FloatVector2 size(100, 60);
	IntVector2 pos(0, 500);
	IntVector2 off(0, 0);
	this->button = plasma::Node::CreateButton(this->node, &wstr_node_name, 0, &wstr_node_text, &pos, &off);
	this->button->SetCallback(2, mod_toggle, 1, 1);
	this->button->widget1->SetSize(&size);

	// Create scroll bar buttons
	void(*scroll_up)(uint64_t) = ScrollUp;
	void(*scroll_down)(uint64_t) = ScrollDown;
	//void(*mod_toggle)(uint64_t) = ModTogglePressed;
	const std::wstring wstr_upbutton(L"upbutton");
	plasma::Node* up_button = game->plasma_engine->root_node->FindChildByName(&wstr_upbutton);
	if (up_button != nullptr) {
		this->up_button = up_button->CreateDeepCopy(this->node);
	}
	const std::wstring wstr_downbutton(L"downbutton");
	plasma::Node* down_button = game->plasma_engine->root_node->FindChildByName(&wstr_downbutton);
	if (down_button != nullptr) {
		this->down_button = down_button->CreateDeepCopy(this->node);
	}
	const std::wstring wstr_scrollbutton(L"scrollbutton");
	plasma::Node* scroll_button = game->plasma_engine->root_node->FindChildByName(&wstr_scrollbutton);
	if (scroll_button != nullptr) {
		this->scroll_button = scroll_button->CreateDeepCopy(this->node);
	}

	this->up_button->SetCallback(2, scroll_up, 1, 1);
	this->down_button->SetCallback(2, scroll_down, 1, 1);

	// Fill the artificial vtable
	for (int i = 0; i < 43; ++i)
	{
		this->artificial_vtable[i] = VTABLE[i];
	}

	// Manually set vtable
	size_t* vptr = (size_t*)this;
	*vptr = (size_t)this->artificial_vtable; //(size_t)CWOffset(0x46CED8);

	return this;
}

void mod::ModWidget::MouseUp(cube::MouseButton mouse_button)
{
	if (mouse_button != cube::MouseButton::LeftMouseButton)
	{
		return;
	}
	switch (this->hover_state)
	{
	case HoverState::Exit:
		this->node->SetVisibility(false);
		if (this->changed)
		{
			// Restart the game
			char* argument_list[] = { (char *)"cubeworld.exe", NULL };
			_execvp("cubeworld.exe", argument_list);
		}
		break;
	case HoverState::Toggle:
		break;
	default:

		break;
	}
}

void mod::ModWidget::ModTogglePressed(uint64_t value)
{
	mod::ModWidget* widget = mod::ModWidget::GetModWidget();
	if (widget == nullptr) return;

	if (widget->selected < 0 || widget->selected >= widget->mods->size()) return;

	widget->mods->at(widget->selected)->enabled = !widget->mods->at(widget->selected)->enabled;
	ModWidget::StoreSave(widget->mods);
	widget->changed = true;
}

void mod::ModWidget::ScrollUp(uint64_t value)
{
	mod::ModWidget* widget = mod::ModWidget::GetModWidget();
	if (widget == nullptr) return;

	widget->scroll_value--;
	if (widget->scroll_value < 0) {
		widget->scroll_value = 0;
	}
}

void mod::ModWidget::ScrollDown(uint64_t value)
{
	mod::ModWidget* widget = mod::ModWidget::GetModWidget();
	if (widget == nullptr) return;

	widget->scroll_value++;
	if (widget->scroll_value >= widget->mods->size()) {
		widget->scroll_value = widget->mods->size()-1;
	}
}

mod::ModWidget* mod::ModWidget::GetModWidget()
{
	auto game = cube::GetGame();
	std::wstring wstr_mod_node(L"mod-node");
	plasma::Node* mod_node = game->plasma_engine->root_node->FindChildByName(&wstr_mod_node);

	if (mod_node == nullptr) return nullptr;
	mod::ModWidget* widget = (mod::ModWidget*)mod_node->widget1;
	return widget;
}

std::wstring* mod::ModWidget::GetSlicedModDescription(std::wstring* str)
{
	const static int line_length = 27;
	int last_space = -1;
	int i_offset = 0;
	std::wstring* final_string(str);
	std::wstring new_line(L"\n");

	const wchar_t* c = str->c_str();
	for (int index = 0; index < str->size(); index++) {
		if (wcsncmp(&c[index], L" ", 1) == 0) {
			last_space = index;
		}

		if (index-i_offset > line_length) {
			if (last_space == -1) last_space = index;
			final_string->replace(last_space, 1, new_line);
			i_offset = last_space;
		}
	}

	return final_string;
}

int mod::ModWidget::GetDescriptionLines(std::wstring* str)
{
	std::wstring new_line(L"\n");
	int amount = 1;
	const wchar_t* c = str->c_str();

	for (int index = 0; index < str->size(); index++) {
		if (wcsncmp(&c[index], new_line.c_str(), 1) == 0) {
			amount++;
		}
	}
	return amount;
}

void mod::ModWidget::Draw(ModWidget* widget)
{
	const static float text_size = 18.0f; // Original	18.0f
	const static float border_size = 4.0f; // Original	4.0f
	const static float title_size = 25.0f;
	const static float text_offset = 10.0f;
	const static float desc_offset = 20.0f;

	cube::Game* game = widget->game;

	FloatRGBA text_color(1.0f, 1.0f, 1.0f, 1.0f);
	FloatRGBA hover_color(0.2f, 1.0f, 1.0f, 1.0f);
	FloatRGBA warn_color(1.0f, 0.65f, 0.0f, 1.0f);
	FloatRGBA desc_color(0.5f, 0.5f, 1.0f, 1.0f);
	FloatRGBA disabled_color(1.0f, 1.0f, 1.0f, 0.2f);
	FloatRGBA disabled_desc_color(0.5f, 0.5f, 1.0f, 0.5f);
	FloatRGBA border_color(0.0f, 0.0f, 0.0f, 1.0f);

	FloatVector2 mouse_pos;
	FloatVector2 pos(0, 0);
	FloatVector2 size(500, 500);
	FloatVector2 scroll_size(16, 340);

	std::wstring wstr_title(L"Mods");
	std::wstring wstr_reminder(L"If you change something \n the game restarts to \n reload all the mods!");
	std::wstring wstr_next(L">");
	std::wstring wstr_prev(L"<");
	std::wstring wstr_x(L"X");

	std::wstring wstr_enable(L"Enable");
	std::wstring wstr_disable(L"Disable");

	// Translate background and node
	widget->node->Translate(game->width/2, game->height/2, -size.x/2, -size.y/2);
	widget->background->Translate(game->width / 2, game->height / 2, -size.x / 2, -size.y / 2);
	widget->up_button->Translate(game->width / 2, game->height / 2, -size.x / 2 + 475, -size.y / 2 + 50);
	widget->down_button->Translate(game->width / 2, game->height / 2, -size.x / 2 + 475, -size.y / 2 + 450);
	widget->scroll_button->Translate(game->width / 2, game->height / 2, -size.x / 2 + 485, -size.y / 2 + 85);
	widget->scroll_button->widget1->SetSize(&scroll_size);

	// Scale background and node
	widget->SetSize(&size);
	widget->background->widget1->SetSize(&size);

	// Get mouse position in the widget
	mouse_pos = *widget->GetRelativeMousePosition(&mouse_pos);

	// Set hover to 0
	widget->hover_state = ModWidget::HoverState::None;

	// Text settings
	widget->SetTextSize(text_size);
	widget->SetTextColor(&text_color);
	widget->SetBorderSize(border_size);
	widget->SetBorderColor(&border_color);
	widget->SetTextPivot(plasma::TextPivot::Center);

	// Draw title
	widget->SetTextSize(title_size);
	widget->DrawString(&pos, &wstr_title, size.x/2, 20 + text_size);

	// Draw x to exit
	widget->SetTextPivot(plasma::TextPivot::Right);
	if (plasma::Widget::IsSquareHovered(&mouse_pos, size.x - 30, 20, 20, 30))
	{
		widget->SetTextColor(&hover_color);
		widget->hover_state = ModWidget::HoverState::Exit;
	}
	widget->DrawString(&pos, &wstr_x, size.x - 10, 20 + text_size);

	// Draw reminder
	widget->SetTextColor(&warn_color);
	widget->SetTextSize(text_size - 5);
	widget->SetTextPivot(plasma::TextPivot::Center);
	widget->DrawString(&pos, &wstr_reminder, size.x / 2, 2 * (10 + text_size));

	// Draw mods
	int y_count = 0;
	int current_height = 0;
	widget->max_height = 1;

	int empty_space = 0;

	widget->button->SetVisibility(false);
	for (int i = 0; i < widget->mods->size(); i++)
	{
		DLL* dll = widget->mods->at(i);
		FloatRGBA* name_color_ptr = &text_color;
		FloatRGBA* desc_color_ptr = &desc_color;
		if (!dll->enabled)
		{
			name_color_ptr = &disabled_color;
			desc_color_ptr = &disabled_desc_color;
		}

		int y_pos = 4 * (text_offset + text_size) + current_height;
		std::wstring temp_desc = std::wstring(L"This is a template description to test if the wrapping is working fine and a lot of nothing.");
		temp_desc.append(std::to_wstring(game->gui.scale));
		std::wstring* desc = widget->GetSlicedModDescription(&temp_desc);
		int desc_height = widget->GetDescriptionLines(desc) * text_size;
		int mod_height = max(35, desc_offset + desc_height);

		widget->max_height += mod_height;

		if (y_pos + mod_height > size.y || i < widget->scroll_value) {
			continue;
		}

		widget->SetTextPivot(plasma::TextPivot::Center);
		if (plasma::Widget::IsSquareHovered(&mouse_pos, 0, y_pos - 20, size.x, mod_height-1)) // this -1 is avoiding overlaping on two mods at the same time
		{
			// Print text inside of the button 'disable' or 'enable'
			// Since button node does not change text position based on button size.
			widget->SetTextColor(&text_color);
			if (!dll->enabled) {
				widget->DrawString(&pos, &wstr_enable, 415, y_pos + max(35, desc_height) / 2);
			}
			else {
				widget->DrawString(&pos, &wstr_disable, 415, y_pos + max(35, desc_height) / 2);
			}

			widget->button->SetVisibility(true);
			widget->button->Translate(game->width / 2, game->height / 2, -size.x / 2 + 365, -size.y / 2 + y_pos - 36 + max(35, desc_height) / 2);

			name_color_ptr = &hover_color;
			desc_color_ptr = &desc_color;
			widget->hover_state = HoverState::Toggle;
			widget->selected = i;
		}
		widget->SetTextPivot(plasma::TextPivot::Left);
		std::wstring name = L"- " + std::wstring(dll->fileName.begin() + 5, dll->fileName.end());

		if (name.size() > 45)
		{
			name = name.substr(0, 42) + L"...";
		}

		widget->SetTextColor(name_color_ptr);
		widget->DrawString(&pos, &name, 20, y_pos);
		widget->SetTextColor(desc_color_ptr);
		widget->DrawString(&pos, desc, 50, y_pos+desc_offset);

		current_height += mod_height;
		y_count++;
		empty_space = max(size.y - current_height, 0);
	}

	// Sorry Nichiren you did an amazing job, but i have to replace this :]
	if (y_count < widget->mods->size() || widget->scroll_value > 0) { // if all the mods are not rendered on screen
		// Apply Transformation and Size modification to ScrollBar here!
		widget->scroll_button->widget1->SetSize(scroll_size.x, (size.y / (widget->max_height+empty_space))*scroll_size.y);
		int scroll_pos = ((scroll_size.y) / (widget->mods->size()));
		widget->scroll_button->Translate(game->width / 2, game->height / 2, -size.x / 2 + 485, -size.y / 2 + 85 + scroll_pos * widget->scroll_value);
	}
}

void mod::ModWidget::Init()
{
	void* NULLSUB = CWOffset(0xE8A20);
	void* RETZERO = CWOffset(0x368230);

	void* vtab[43] = {
	CWOffset(0x268B40),
	Draw,				// void Draw(plasma::Widget*)
	CWOffset(0x26A720),
	CWOffset(0x26A720),
	RETZERO,
	RETZERO,
	NULLSUB,
	CWOffset(0x32B830),
	CWOffset(0x32BFD0),
	CWOffset(0x32BD70),
	NULLSUB,
	CWOffset(0x32B990),
	CWOffset(0x32BB40),
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	CWOffset(0x32BB80),		// void OnMouseOver(plasma::Widget*)
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	NULLSUB,
	CWOffset(0x32B5A0),
	CWOffset(0x32B6B0),
	NULLSUB,
	NULLSUB,
	CWOffset(0x32B6E0),
	CWOffset(0x32A2C0),		// plasma::Widget* CreateCopy(plasma::Widget*);
	CWOffset(0x32A8D0),
	NULLSUB
	};

	for (int i = 0; i < 43; ++i)
	{
		VTABLE[i] = vtab[i];
	}
}

void mod::ModWidget::LoadSave(std::vector<DLL*>* mods)
{
	std::ifstream in(file_name.c_str());
	std::string line;

	while (getline(in, line)) {
		auto pos = line.find(":");
		if (pos != std::string::npos)
		{
			std::string name(line.substr(0, pos));
			bool enabled = stoi(line.substr(pos + 1, line.size() - 1));
			for (DLL* dll : *mods)
			{
				if (!name.compare(dll->fileName))
				{
					dll->enabled = enabled;
				}
			}
		}
	}
}

void mod::ModWidget::StoreSave(std::vector<DLL*>* mods)
{
	std::ofstream out(file_name.c_str());
	for (DLL* dll : *mods)
	{
		out << dll->fileName << ":" << dll->enabled << "\n";
	}
	out.close();
}
