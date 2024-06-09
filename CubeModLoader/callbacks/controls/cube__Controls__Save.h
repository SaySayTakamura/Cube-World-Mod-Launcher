#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" uint64_t cube__Controls__Save(cube::Game* game, cube::Controls* controls)
{
    std::ofstream file("controls.cfg");

    if (!file.is_open()) {
        return 0LL; // nullptr;
    }

    file << "ButtonAttack " << controls->button_attack << " " << controls->button_attack_2 << "\n";
    file << "ButtonSpecialAttack " << controls->button_special_attack << " " << controls->button_special_attack_2 << "\n";
    file << "ButtonQuickItem " << controls->button_quick_item << " " << controls->button_quick_item_2 << "\n";
    file << "ButtonUp " << controls->button_up << " " << controls->button_up_2 << "\n";
    file << "ButtonDown " << controls->button_down << " " << controls->button_down_2 << "\n";
    file << "ButtonLeft " << controls->button_left << " " << controls->button_left_2 << "\n";
    file << "ButtonRight " << controls->button_right << " " << controls->button_right_2 << "\n";
    file << "ButtonJump " << controls->button_jump << " " << controls->button_jump_2 << "\n";
    file << "ButtonDodge " << controls->button_dodge << " " << controls->button_dodge_2 << "\n";
    file << "ButtonUse " << controls->button_use << " " << controls->button_use_2 << "\n";
    file << "ButtonLamp " << controls->button_lamp << " " << controls->button_lamp_2 << "\n";
    file << "ButtonUltimateSkill " << controls->button_ultimate_skill << " " << controls->button_ultimate_skill_2 << "\n";
    file << "ButtonClassSkill " << controls->button_class_skill << " " << controls->button_class_skill_2 << "\n";
    file << "ButtonWalk " << controls->button_walk << " " << controls->button_walk_2 << "\n";
    file << "ButtonCallPet " << controls->button_call_pet << " " << controls->button_call_pet_2 << "\n";
    file << "ButtonWorldMap " << controls->button_world_map << " " << controls->button_world_map_2 << "\n";
    file << "ButtonRingMenu " << controls->button_ring_menu << " " << controls->button_ring_menu_2 << "\n";
    file << "ButtonInventory " << controls->button_inventory << " " << controls->button_inventory_2 << "\n";
    file << "ButtonMultiplayerMenu " << controls->button_multiplayer_menu << " " << controls->button_multiplayer_menu_2 << "\n";
    file << "ButtonCraftingMenu " << controls->button_crafting_menu << " " << controls->button_crafting_menu_2 << "\n";
    file << "ButtonSystemMenu " << controls->button_system_menu << " " << controls->button_system_menu_2 << "\n";
    file << "ButtonZoomIn " << controls->button_zoom_in << " " << controls->button_zoom_in_2 << "\n";
    file << "ButtonZoomOut " << controls->button_zoom_out << " " << controls->button_zoom_out_2 << "\n";

    for (DLL* dll : modDLLs) {
        std::map<std::string, modhelper::KeybindManager::KeybindValue>* keybinds = dll->mod->keybind_manager.GetKeybinds();
        for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = keybinds->begin(); it != keybinds->end(); ++it) {
            file << it->first << " " << it->second.first << " " << it->second.second << "\n";
        }
    }

    file.close();
	return 0LL; // nullptr;
}

overwrite_function(0x438E0, cube__Controls__Save)