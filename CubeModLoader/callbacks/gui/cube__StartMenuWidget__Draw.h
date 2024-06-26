#pragma once
#include "../../CWSDK/cwsdk.h"

void DrawModdedText(cube::StartMenuWidget* widget)
{
	// Color rotation of the modded text
	static float i = 0;
	static int dir = 0;
	int height;

	if (dir == 0)
	{
		i += 0.01f;
		if (i >= 1.0f)
		{
			dir = 1;
			i = 1.0f;
		}
	}
	else {
		i -= 0.01f;
		if (i <= 0.0f)
		{
			dir = 0;
			i = 0.0f;
		}
	}

	FloatRGBA border_color(0.0f, 0.0f, 0.0f, 1.0f);
	FloatRGBA modded_color(i, 1.0f - i, 0.5f + 0.5f * i, 1.0f);
	FloatVector2 pos = FloatVector2(0, 0);
	std::wstring txt_modded = L"Modded";

	height = - widget->game->height / 3;

	// Draw modded text
	widget->SetTextSize(200.0f);
	widget->SetBorderSize(18.0f);
	widget->SetTextPivot(plasma::TextPivot::Center);
	widget->SetBorderColor(&border_color);
	widget->SetTextColor(&modded_color);
	widget->DrawString(&pos, &txt_modded, 0.5* widget->GetXSize(), height);
}

extern "C" void cube__StartMenuWidget__Draw(cube::StartMenuWidget * widget)
{
	const static float text_size = 36.0f; // Original	18.0f
	const static float border_size = 4.0f; // Original	4.0f
	const int num_btns = 5;

	float width;
	int y_offset = -20;
	int btn_height = 50;
	bool other_widget_active;

	FloatVector2 pos = FloatVector2(0, 0);
	FloatVector2 mouse_pos;
	FloatRGBA text_color(1.0f, 1.0f, 1.0f, 1.0f);
	FloatRGBA hover_color(0.2f, 1.0f, 1.0f, 1.0f);
	FloatRGBA disabled_color(1.0f, 1.0f, 1.0f, 0.2f);
	FloatRGBA border_color(0.0f, 0.0f, 0.0f, 1.0f);


	std::wstring font1 = L"resource1.dat";
	std::wstring font2 = L"resource2.dat";
	
	std::wstring btn_txt[num_btns] = {
		L"Start Game",
		L"Continue",
		L"Mods",
		L"Options",
		L"Exit",
	};

	cube::StartMenuWidget::HoverState states[num_btns] = {
		cube::StartMenuWidget::HoverState::StartGame,
		cube::StartMenuWidget::HoverState::Continue,
		cube::StartMenuWidget::HoverState::Mods,
		cube::StartMenuWidget::HoverState::Options,
		cube::StartMenuWidget::HoverState::Exit,
	};

	std::wstring credits[] = {
		L"Copyright (c) 2019 Picroma e.K.",
		L"Youtube for mods: TheBagel3",
		L"Modloader by ChrisMiuchiz and Nichiren.",
	};

	widget->SetScalableFont(&font2);
	DrawModdedText(widget);

	mouse_pos = *widget->GetRelativeMousePosition(&mouse_pos);
	width = widget->GetXSize();
	other_widget_active = widget->game->gui.options_widget->node->display->IsVisible();

	// If options widget is not active, check if the mod widget is active
	if (!other_widget_active)
	{
		std::wstring wstr_mod_node(L"mod-node");
		plasma::Node* node = widget->game->plasma_engine->root_node->FindChildByName(&wstr_mod_node);
		if (node != nullptr && node->IsVisible())
		{
			other_widget_active = true;
		}
	}

	widget->SetTextSize(text_size);
	widget->SetBorderSize(border_size);
	widget->SetTextPivot(plasma::TextPivot::Center);
	widget->SetBorderColor(&border_color);
	widget->hover_state = cube::StartMenuWidget::HoverState::None;

	// Render all buttons
	for (int i = 0; i < num_btns; i++)
	{
		int btn_y = y_offset + i * btn_height;
		if (!plasma::Widget::IsSquareHovered(&mouse_pos, 0, btn_y - 20, width, 30))
		{
			widget->SetTextColor(&text_color);
		}
		else
		{
			widget->hover_state = states[i];
			widget->SetTextColor(&hover_color);
		}

		if (states[i] == cube::StartMenuWidget::HoverState::Continue)
		{
			int character_slot = widget->game->current_character_slot;
			int character_count = widget->game->saved_characters.size();

			if (character_slot < 0 || character_slot >= character_count)
			{
				if (plasma::Widget::IsSquareHovered(&mouse_pos, 0, btn_y - 20, width, 30))
				{
					widget->hover_state = cube::StartMenuWidget::HoverState::None;
				}
				widget->SetTextColor(&disabled_color);
			}
		}

		widget->DrawString(&pos, &btn_txt[i], 0.5 * width, btn_y);
	}

	widget->SetScalableFont(&font1);
	widget->SetTextPivot(plasma::TextPivot::Left);
	widget->SetTextSize(12.0f);
	widget->SetBorderSize(3.0f);
	widget->SetTextColor(&text_color);

	FloatVector2 position;
	position = *widget->GetSomeVector2(&position);

	Matrix4 mat;
	widget->node->LoadSomeMatrix(&mat);
	float f9 = 10.0f;
	float f1 = widget->game->height - 15;
	float f8 = mat._24;
	float f3 = f8;
	f3 *= f1;
	float f12 = mat._14;
	float f0 = f12;
	f0 *= f9;
	f3 += f0;
	f3 += mat._44;
	float f13 = mat._22;
	float f2 = f13;
	f2 *= f1;
	float f10 = mat._12;
	f0 = f10;
	f0 *= f9;
	f2 += f0;
	f2 += mat._42;
	float f11 = mat._21;
	float f7 = f11;
	f7 *= f1;
	float f14 = mat._11;
	f0 = f14;
	f0 *= f9;
	f7 += f0;
	f0 += mat._41;
	f9 = 1.0f;
	float f6 = f9;
	f6 /= f3;
	f7 *= f6;
	f6 *= f2;

	int offset = 20;
	for (int i = 0; i < 3; i++)
	{
		widget->DrawString(&pos, &credits[i], f7 + (width - widget->game->width) / 2, f6 - i * offset);
		widget->SetScalableFont(&font2);
		widget->SetTextSize(20.0f);
		offset = 25;
	}

	std::wstring versions[] = {
		L"Game: 1.0.0-1",
		L"Modloader: " + to_wstring(MOD_MAJOR_VERSION) + L"." + to_wstring(MOD_MINOR_VERSION),
	};
	widget->SetScalableFont(&font1);
	widget->SetTextSize(12.0f);
	widget->SetTextPivot(plasma::TextPivot::Right);

	for (int i = 0; i < 2; i++)
	{
		widget->DrawString(&pos, &versions[i], -f7 + (width + widget->game->width) / 2, f6 - i * 20);
	}
	
};

overwrite_function(0x291210, cube__StartMenuWidget__Draw);