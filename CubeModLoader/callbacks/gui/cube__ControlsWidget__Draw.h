#include "cwsdk.h"

int wParamToDInput(int wParam_id) {
    if (wParam_id < 0x07) return wParam_id;
    if (wParam_id == VK_BACK) return DIK_BACK;
    if (wParam_id == VK_TAB) return DIK_TAB;
    if (wParam_id == VK_RETURN) return DIK_RETURN;
    if (wParam_id == VK_SHIFT) return DIK_LSHIFT;
    if (wParam_id == VK_CONTROL) return DIK_LCONTROL;
    if (wParam_id == VK_MENU) return DIK_LMENU;
    if (wParam_id == VK_PAUSE) return DIK_PAUSE;
    if (wParam_id == VK_CAPITAL) return DIK_CAPITAL;
    if (wParam_id == VK_KANA) return DIK_KANA;
    if (wParam_id == VK_KANJI) return DIK_KANJI;
    if (wParam_id == VK_ESCAPE) return DIK_ESCAPE;
    if (wParam_id == VK_CONVERT) return DIK_CONVERT;
    if (wParam_id == VK_NONCONVERT) return DIK_NOCONVERT;
    if (wParam_id == VK_SPACE) return DIK_SPACE;
    if (wParam_id == VK_PRIOR) return DIK_PRIOR;
    if (wParam_id == VK_NEXT) return DIK_NEXT;
    if (wParam_id == VK_END) return DIK_END;
    if (wParam_id == VK_HOME) return DIK_HOME;
    if (wParam_id == VK_LEFT) return DIK_LEFT;
    if (wParam_id == VK_RIGHT) return DIK_RIGHT;
    if (wParam_id == VK_UP) return DIK_UP;
    if (wParam_id == VK_DOWN) return DIK_DOWN;
    if (wParam_id == VK_INSERT) return DIK_INSERT;
    if (wParam_id == VK_DELETE) return DIK_DELETE;
    if (wParam_id == 0x30) return DIK_0;
    if (wParam_id == 0x31) return DIK_1;
    if (wParam_id == 0x32) return DIK_2;
    if (wParam_id == 0x33) return DIK_3;
    if (wParam_id == 0x34) return DIK_4;
    if (wParam_id == 0x35) return DIK_5;
    if (wParam_id == 0x36) return DIK_6;
    if (wParam_id == 0x37) return DIK_7;
    if (wParam_id == 0x38) return DIK_8;
    if (wParam_id == 0x39) return DIK_9;
    if (wParam_id == 0x41) return DIK_A;
    if (wParam_id == 0x42) return DIK_B;
    if (wParam_id == 0x43) return DIK_C;
    if (wParam_id == 0x44) return DIK_D;
    if (wParam_id == 0x45) return DIK_E;
    if (wParam_id == 0x46) return DIK_F;
    if (wParam_id == 0x47) return DIK_G;
    if (wParam_id == 0x48) return DIK_H;
    if (wParam_id == 0x49) return DIK_I;
    if (wParam_id == 0x4A) return DIK_J;
    if (wParam_id == 0x4B) return DIK_K;
    if (wParam_id == 0x4C) return DIK_L;
    if (wParam_id == 0x4D) return DIK_M;
    if (wParam_id == 0x4E) return DIK_N;
    if (wParam_id == 0x4F) return DIK_O;
    if (wParam_id == 0x50) return DIK_P;
    if (wParam_id == 0x51) return DIK_Q;
    if (wParam_id == 0x52) return DIK_R;
    if (wParam_id == 0x53) return DIK_S;
    if (wParam_id == 0x54) return DIK_T;
    if (wParam_id == 0x55) return DIK_U;
    if (wParam_id == 0x56) return DIK_V;
    if (wParam_id == 0x57) return DIK_W;
    if (wParam_id == 0x58) return DIK_X;
    if (wParam_id == 0x59) return DIK_Y;
    if (wParam_id == 0x5A) return DIK_Z;
    if (wParam_id == VK_LWIN) return DIK_LWIN;
    if (wParam_id == VK_RWIN) return DIK_RWIN;
    if (wParam_id == VK_APPS) return DIK_APPS;
    if (wParam_id == VK_NUMPAD0) return DIK_NUMPAD0;
    if (wParam_id == VK_NUMPAD1) return DIK_NUMPAD1;
    if (wParam_id == VK_NUMPAD2) return DIK_NUMPAD2;
    if (wParam_id == VK_NUMPAD3) return DIK_NUMPAD3;
    if (wParam_id == VK_NUMPAD4) return DIK_NUMPAD4;
    if (wParam_id == VK_NUMPAD5) return DIK_NUMPAD5;
    if (wParam_id == VK_NUMPAD6) return DIK_NUMPAD6;
    if (wParam_id == VK_NUMPAD7) return DIK_NUMPAD7;
    if (wParam_id == VK_NUMPAD8) return DIK_NUMPAD8;
    if (wParam_id == VK_NUMPAD9) return DIK_NUMPAD9;
    if (wParam_id == VK_MULTIPLY) return DIK_MULTIPLY;
    if (wParam_id == VK_ADD) return DIK_ADD;
    if (wParam_id == VK_SUBTRACT) return DIK_SUBTRACT;
    if (wParam_id == VK_DECIMAL) return DIK_DECIMAL;
    if (wParam_id == VK_DIVIDE) return DIK_DIVIDE;
    if (wParam_id == VK_F1) return DIK_F1;
    if (wParam_id == VK_F2) return DIK_F2;
    if (wParam_id == VK_F3) return DIK_F3;
    if (wParam_id == VK_F4) return DIK_F4;
    if (wParam_id == VK_F5) return DIK_F5;
    if (wParam_id == VK_F6) return DIK_F6;
    if (wParam_id == VK_F7) return DIK_F7;
    if (wParam_id == VK_F8) return DIK_F8;
    if (wParam_id == VK_F9) return DIK_F9;
    if (wParam_id == VK_F10) return DIK_F10;
    if (wParam_id == VK_F11) return DIK_F11;
    if (wParam_id == VK_F12) return DIK_F12;
    if (wParam_id == VK_F13) return DIK_F13;
    if (wParam_id == VK_F14) return DIK_F14;
    if (wParam_id == VK_F15) return DIK_F15;
    if (wParam_id == VK_NUMLOCK) return DIK_NUMLOCK;
    if (wParam_id == VK_SCROLL) return DIK_SCROLL;
    if (wParam_id == VK_LSHIFT) return DIK_LSHIFT;
    if (wParam_id == VK_RSHIFT) return DIK_RSHIFT;
    if (wParam_id == VK_LCONTROL) return DIK_LCONTROL;
    if (wParam_id == VK_RCONTROL) return DIK_RCONTROL;
    if (wParam_id == VK_LMENU) return DIK_LMENU;
    if (wParam_id == VK_RMENU) return DIK_RMENU;
    return 0xFF;
}

extern "C" void cube__ControlsWidget__Draw(cube::ControlsWidget * widget)
{
    std::map<std::string, std::wstring*> displayNameMap = {};
    std::map<std::string, modhelper::KeybindManager::KeybindValue> keybinds = {};
    for (DLL* dll : modDLLs) {
        std::map<std::string, modhelper::KeybindManager::KeybindValue>* mod_keybinds = dll->mod->keybind_manager.GetKeybinds();
        for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = mod_keybinds->begin(); it != mod_keybinds->end(); ++it) {
            displayNameMap.insert({ it->first, dll->mod->keybind_manager.GetKeybindDisplayName(it->first) });
            keybinds.insert({ it->first, it->second });
        }
    }

    int keybinds_size = keybinds.size();

    float YSize = widget->GetYSize();
    float v12 = 27.0;
    int scroll_position = widget->scroll_position;
    int bottom_bar_size_y = 120.0;
    int text_box_size_y = (YSize - bottom_bar_size_y);
    int box_end_pos_y = scroll_position + text_box_size_y / 30;
    if (scroll_position < 0)
        scroll_position = 0;
    int v15 = 0;
    if (box_end_pos_y >= 0)
        v15 = box_end_pos_y;

    FloatVector2 relative_mouse_pos;
    widget->GetRelativeMousePosition(&relative_mouse_pos);

    widget->hovered_index = -1;
    widget->SetTextSize(12.0f);
    widget->SetBorderSize(3.0f);

    if (widget->game->gap17C8[400]) {
        widget->selected_index = -1;
    }
        int widget_size_x = widget->GetXSize();
        int* control_ptr = &widget->controls.button_attack + 2 * scroll_position;
        for (int id = v15 - scroll_position; id > 0; id--) {
            widget->text_pivot = plasma::TextPivot::Left;
            FloatRGBA color = { 1.0, 1.0, 1.0, 1.0 }; // White
            std::pair<int, int> key = { 0, 0 };
            std::wstring keybind_display_name;

            if (v15-id >= 23) {
                if (v15 - id < 23 + keybinds_size) {
                    int keybind_id = (v15 - id) - 23;
                    int i = 0;
                    for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = keybinds.begin(); it != keybinds.end(); it++) {
                        if (i == keybind_id) {
                            keybind_display_name = *displayNameMap.at(it->first);
                            key.first = it->second.first;
                            key.second = it->second.second;
                            break;
                        }
                        i++;
                    }
                    control_ptr = &key.first;
                }
                else {
                    break;
                }
            }
            int selected_index = widget->selected_index;
            if (scroll_position == selected_index) {
                color = { 1.0, 0.35, 0.35, 1.0 }; // Red
                ((uint64_t(*)(cube::BaseWidget*, FloatRGBA*))CWOffset(0x269160))(widget, &color);
                FloatRGBA border_color = { 0, 0, 0, 1 };
                widget->SetBorderColor(&border_color);
                if (v15 - id < 23)
                    ((std::wstring * (*)(std::wstring*, int))CWOffset(0x42670))(&keybind_display_name, scroll_position);
                FloatVector2 pos = { 0, 0 };
                widget->DrawString(&pos, &keybind_display_name, 20.0, v12);
                widget->text_pivot = plasma::TextPivot::Center;
                std::wstring keybind_key_name = L"Press a key";
                FloatVector2 pos2 = { 0, 0 };
                widget->DrawString(&pos2, &keybind_key_name, ((widget_size_x - 250.0) * 0.5) + 240.0, v12);
            }
            else {
                if (*control_ptr == 0 && *(control_ptr + 1) == 0) {
                    color = { 0.2, 1.0, 0.2, 1.0 }; // Green
                }
                if (selected_index < 0 && !widget->game->gap17C8[400] && relative_mouse_pos.x >= 0.0)
                {
                    if ((widget_size_x - 40.0) > relative_mouse_pos.x
                        && relative_mouse_pos.y >= (v12 - 20.0)
                        && (v12 + 10.0) > relative_mouse_pos.y)
                    {
                        widget->hovered_index = scroll_position;
                        color = { 0.2, 1.0, 1.0, 1.0 }; // Cyan
                    }
                }
                ((uint64_t(*)(cube::BaseWidget*, FloatRGBA*))CWOffset(0x269160))(widget, &color);
                FloatRGBA border_color = { 0, 0, 0, 1 };
                widget->SetBorderColor(&border_color);
                if (v15 - id < 23)
                    ((std::wstring * (*)(std::wstring*, int))CWOffset(0x42670))(&keybind_display_name, scroll_position);
                FloatVector2 pos = { 0, 0 };
                widget->DrawString(&pos, &keybind_display_name, 20.0, v12);
                widget->text_pivot = plasma::TextPivot::Center;
                std::wstring keybind_key_name;
                ((std::wstring * (*)(cube::Game::KeyNames*, std::wstring*, int*))CWOffset(0x4C830))(&widget->game->key_info, &keybind_key_name, control_ptr);
                FloatVector2 pos2 = { 0, 0 };
                widget->DrawString(&pos2, &keybind_key_name, ((widget_size_x - 250.0) * 0.5) + 240.0, v12);
            }
            v12 = v12 + 30.0;
            ++scroll_position;
            control_ptr += 2;
        }

    if (widget->upbutton)
    {
        FloatRGBA color = { 1, 1, 1, 1 };
        //if (widget->upbutton->widget1->CW_32B0C0()) // THIS CRASH
        if (widget->upbutton->IsMouseOverNode()) // Use this as replacement
            color = { 0, 1, 1, 1 };
        auto display = widget->upbutton->display;
        int frame_id = 2LL * display->fill.current_frame;
        plasma::Vector<4, float>* color_data = &display->fill.data.at(frame_id);
        color_data->Set(0, color.red);
        color_data->Set(1, color.green);
        color_data->Set(2, color.blue);
        color_data->Set(3, color.alpha);
    }

    if (widget->downbutton)
    {
        FloatRGBA color = { 1, 1, 1, 1 };
        if (widget->downbutton->IsMouseOverNode())
            color = { 0, 1, 1, 1 };
        auto display = widget->downbutton->display;
        int frame_id = 2LL * display->fill.current_frame;
        plasma::Vector<4, float>* color_data = &display->fill.data.at(frame_id);
        color_data->Set(0, color.red);
        color_data->Set(1, color.green);
        color_data->Set(2, color.blue);
        color_data->Set(3, color.alpha);
    }

    if (widget->scrollbutton)
    {
        FloatRGBA color = { 1, 1, 1, 1 };
        if (widget->scrollbutton->IsMouseOverNode())
            color = { 0, 1, 1, 1 };
        auto display = widget->scrollbutton->display;
        int frame_id = 2LL * display->fill.current_frame;
        plasma::Vector<4, float>* color_data = &display->fill.data.at(frame_id);
        color_data->Set(0, color.red);
        color_data->Set(1, color.green);
        color_data->Set(2, color.blue);
        color_data->Set(3, color.alpha);
    }
    widget->text_pivot = plasma::TextPivot::Left;
}

overwrite_function(0x276203, cube__ControlsWidget__Draw);