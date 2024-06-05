#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" void cube__ControlsWidget__ResetKeybinds(cube::ControlsWidget * widget)
{
	widget->controls.button_attack = 0;
	widget->controls.button_special_attack = 1;
	widget->controls.button_quick_item = DIK_Q;
	widget->controls.button_up = DIK_W;
	widget->controls.button_down = DIK_S;
	widget->controls.button_left = DIK_A;
	widget->controls.button_right = DIK_D;
	widget->controls.button_jump = DIK_SPACE;
	widget->controls.button_dodge = 2;
	widget->controls.button_use = DIK_E;
	widget->controls.button_lamp = DIK_F;
	widget->controls.button_ultimate_skill = DIK_R;
	widget->controls.button_walk = DIK_LCONTROL;
	widget->controls.button_class_skill = DIK_LSHIFT;
	widget->controls.button_call_pet = DIK_T;
	widget->controls.button_world_map = DIK_M;
	widget->controls.button_ring_menu = DIK_TAB;
	widget->controls.button_inventory = DIK_B;
	widget->controls.button_multiplayer_menu = DIK_J;
	widget->controls.button_crafting_menu = DIK_C;
	widget->controls.button_system_menu = DIK_O;

	widget->controls.button_attack_2 = 1;
	widget->controls.button_special_attack_2 = 1;
	widget->controls.button_quick_item_2 = 0;
	widget->controls.button_up_2 = 0;
	widget->controls.button_down_2 = 0;
	widget->controls.button_left_2 = 0;
	widget->controls.button_right_2 = 0;
	widget->controls.button_jump_2 = 0;
	widget->controls.button_dodge_2 = 1;
	widget->controls.button_use_2 = 0;
	widget->controls.button_lamp_2 = 0;
	widget->controls.button_ultimate_skill_2 = 0;
	widget->controls.button_walk_2 = 0;
	widget->controls.button_class_skill_2 = 0;
	widget->controls.button_call_pet_2 = 0;
	widget->controls.button_world_map_2 = 0;
	widget->controls.button_ring_menu_2 = 0;
	widget->controls.button_inventory_2 = 0;
	widget->controls.button_multiplayer_menu_2 = 0;
	widget->controls.button_crafting_menu_2 = 0;
	widget->controls.button_system_menu_2 = 0;

	for (DLL* dll : modDLLs) {
		std::map<std::string, modhelper::KeybindManager::KeybindValue>* keybinds = dll->mod->keybind_manager.GetKeybinds();
		std::map<std::string, modhelper::KeybindManager::KeybindValue>* default_keybinds = dll->mod->keybind_manager.GetDefaultKeybinds();
		for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = keybinds->begin(); it != keybinds->end(); it++) {
			modhelper::KeybindManager::KeybindValue* default_key = &default_keybinds->at(it->first);
			it->second.first = default_key->first;
			it->second.second = default_key->second;
		}
	}
}

overwrite_function(0x276A30, cube__ControlsWidget__ResetKeybinds);