#pragma once
#include "../../CWSDK/cwsdk.h"

int DInputToWParam(int dinput_id) {
    if (dinput_id < 0x07) return dinput_id;
    if (dinput_id == DIK_BACK) return VK_BACK;
    if (dinput_id == DIK_TAB) return VK_TAB;
    if (dinput_id == DIK_RETURN) return VK_RETURN;
    if (dinput_id == DIK_PAUSE) return VK_PAUSE;
    if (dinput_id == DIK_CAPITAL) return VK_CAPITAL;
    if (dinput_id == DIK_KANA) return VK_KANA;
    if (dinput_id == DIK_KANJI) return VK_KANJI;
    if (dinput_id == DIK_ESCAPE) return VK_ESCAPE;
    if (dinput_id == DIK_CONVERT) return VK_CONVERT;
    if (dinput_id == DIK_NOCONVERT) return VK_NONCONVERT;
    if (dinput_id == DIK_SPACE) return VK_SPACE;
    if (dinput_id == DIK_PRIOR) return VK_PRIOR;
    if (dinput_id == DIK_NEXT) return VK_NEXT;
    if (dinput_id == DIK_END) return VK_END;
    if (dinput_id == DIK_HOME) return VK_HOME;
    if (dinput_id == DIK_LEFT) return VK_LEFT;
    if (dinput_id == DIK_RIGHT) return VK_RIGHT;
    if (dinput_id == DIK_UP) return VK_UP;
    if (dinput_id == DIK_DOWN) return VK_DOWN;
    if (dinput_id == DIK_INSERT) return VK_INSERT;
    if (dinput_id == DIK_DELETE) return VK_DELETE;
    if (dinput_id == DIK_0) return 0x30;
    if (dinput_id == DIK_1) return 0x31;
    if (dinput_id == DIK_2) return 0x32;
    if (dinput_id == DIK_3) return 0x33;
    if (dinput_id == DIK_4) return 0x34;
    if (dinput_id == DIK_5) return 0x35;
    if (dinput_id == DIK_6) return 0x36;
    if (dinput_id == DIK_7) return 0x37;
    if (dinput_id == DIK_8) return 0x38;
    if (dinput_id == DIK_9) return 0x39;
    if (dinput_id == DIK_A) return 0x41;
    if (dinput_id == DIK_B) return 0x42;
    if (dinput_id == DIK_C) return 0x43;
    if (dinput_id == DIK_D) return 0x44;
    if (dinput_id == DIK_E) return 0x45;
    if (dinput_id == DIK_F) return 0x46;
    if (dinput_id == DIK_G) return 0x47;
    if (dinput_id == DIK_H) return 0x48;
    if (dinput_id == DIK_I) return 0x49;
    if (dinput_id == DIK_J) return 0x4A;
    if (dinput_id == DIK_K) return 0x4B;
    if (dinput_id == DIK_L) return 0x4C;
    if (dinput_id == DIK_M) return 0x4D;
    if (dinput_id == DIK_N) return 0x4E;
    if (dinput_id == DIK_O) return 0x4F;
    if (dinput_id == DIK_P) return 0x50;
    if (dinput_id == DIK_Q) return 0x51;
    if (dinput_id == DIK_R) return 0x52;
    if (dinput_id == DIK_S) return 0x53;
    if (dinput_id == DIK_T) return 0x54;
    if (dinput_id == DIK_U) return 0x55;
    if (dinput_id == DIK_V) return 0x56;
    if (dinput_id == DIK_W) return 0x57;
    if (dinput_id == DIK_X) return 0x58;
    if (dinput_id == DIK_Y) return 0x59;
    if (dinput_id == DIK_Z) return 0x5A;
    if (dinput_id == DIK_LWIN) return VK_LWIN;
    if (dinput_id == DIK_RWIN) return VK_RWIN;
    if (dinput_id == DIK_APPS) return VK_APPS;
    if (dinput_id == DIK_NUMPAD0) return VK_NUMPAD0;
    if (dinput_id == DIK_NUMPAD1) return VK_NUMPAD1;
    if (dinput_id == DIK_NUMPAD2) return VK_NUMPAD2;
    if (dinput_id == DIK_NUMPAD3) return VK_NUMPAD3;
    if (dinput_id == DIK_NUMPAD4) return VK_NUMPAD4;
    if (dinput_id == DIK_NUMPAD5) return VK_NUMPAD5;
    if (dinput_id == DIK_NUMPAD6) return VK_NUMPAD6;
    if (dinput_id == DIK_NUMPAD7) return VK_NUMPAD7;
    if (dinput_id == DIK_NUMPAD8) return VK_NUMPAD8;
    if (dinput_id == DIK_NUMPAD9) return VK_NUMPAD9;
    if (dinput_id == DIK_MULTIPLY) return VK_MULTIPLY;
    if (dinput_id == DIK_ADD) return VK_ADD;
    if (dinput_id == DIK_SUBTRACT) return VK_SUBTRACT;
    if (dinput_id == DIK_DECIMAL) return VK_DECIMAL;
    if (dinput_id == DIK_DIVIDE) return VK_DIVIDE;
    if (dinput_id == DIK_F1) return VK_F1;
    if (dinput_id == DIK_F2) return VK_F2;
    if (dinput_id == DIK_F3) return VK_F3;
    if (dinput_id == DIK_F4) return VK_F4;
    if (dinput_id == DIK_F5) return VK_F5;
    if (dinput_id == DIK_F6) return VK_F6;
    if (dinput_id == DIK_F7) return VK_F7;
    if (dinput_id == DIK_F8) return VK_F8;
    if (dinput_id == DIK_F9) return VK_F9;
    if (dinput_id == DIK_F10) return VK_F10;
    if (dinput_id == DIK_F11) return VK_F11;
    if (dinput_id == DIK_F12) return VK_F12;
    if (dinput_id == DIK_F13) return VK_F13;
    if (dinput_id == DIK_F14) return VK_F14;
    if (dinput_id == DIK_F15) return VK_F15;
    if (dinput_id == DIK_NUMLOCK) return VK_NUMLOCK;
    if (dinput_id == DIK_SCROLL) return VK_SCROLL;
    if (dinput_id == DIK_LSHIFT) return VK_LSHIFT;
    if (dinput_id == DIK_RSHIFT) return VK_RSHIFT;
    if (dinput_id == DIK_LCONTROL) return VK_LCONTROL;
    if (dinput_id == DIK_RCONTROL) return VK_RCONTROL;
    if (dinput_id == DIK_LMENU) return VK_LMENU;
    if (dinput_id == DIK_RMENU) return VK_RMENU;
    return 0xFF;
}

extern "C" void cube__Game__RebindControl(cube::Game * game, int key_data[2])
{
    cube::ControlsWidget* controls_widget = game->gui.controls_widget;

    // Undefine every in-use keybind
    cube::Controls* p_controls = &controls_widget->controls;
    __int64 vanilla_id = 23LL;
    do
    {
        if (p_controls->button_attack_2 == key_data[1] && p_controls->button_attack == key_data[0])
            p_controls->button_attack = 0LL;
        p_controls = (cube::Controls*)(((char*)p_controls) + 8);
        --vanilla_id;
    } while (vanilla_id);
    // Do the same for my keybinds (Not Working) TODO: Fix
    for (DLL* dll : modDLLs) {
        std::map<std::string, modhelper::KeybindManager::KeybindValue>* keybinds = dll->mod->keybind_manager.GetKeybinds();
        for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = keybinds->begin(); it != keybinds->end(); ++it) {
            if (it->second.first == key_data[0] && it->second.second == key_data[1]) {
                it->second.first = 0;
                it->second.second = modhelper::KeybindManager::DeviceIds::Keyboard;
            }
        }
    }

    if (controls_widget->selected_index < 23) {
        cube::Controls* control_ptr = (cube::Controls*)(((char*)&controls_widget->controls) + 8 * controls_widget->selected_index);
        control_ptr->button_attack = key_data[0];
        control_ptr->button_attack_2 = key_data[1];
    }
    else {
        int selected_id = controls_widget->selected_index - 23;
        int cur = 0;
        std::map<std::string, modhelper::KeybindManager::KeybindValue>* keybinds;
        for (DLL* dll : modDLLs) {
            keybinds = dll->mod->keybind_manager.GetKeybinds();
            if (selected_id < cur + keybinds->size()) {
                break;
            }
            cur += keybinds->size();
        }
        int effective_id = selected_id - cur;
        for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = keybinds->begin(); it != keybinds->end(); ++it) {
            if (effective_id == 0) {
                it->second.first = DInputToWParam(key_data[0]);
                it->second.second = (modhelper::KeybindManager::DeviceIds)key_data[1];
            }
            effective_id--;
        }

    }
    controls_widget->hovered_index = -1;
}

overwrite_function(0x8A120, cube__Game__RebindControl);