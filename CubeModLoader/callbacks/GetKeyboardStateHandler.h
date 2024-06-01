#include "cwsdk.h"

void UpdateModControlStates(GenericMod* mod) {
	cube::Game* game = cube::GetGame();
	mod->keybind_manager.old_control_states = mod->keybind_manager.control_states;
	std::map<std::string, modhelper::KeybindManager::KeybindValue>* keybinds = mod->keybind_manager.GetKeybinds();
	for (std::map<std::string, modhelper::KeybindManager::KeybindValue>::iterator it = keybinds->begin(); it != keybinds->end(); ++it) {
		modhelper::KeybindManager::KeybindValue* keybind = &keybinds->at(it->first);
		mod->keybind_manager.control_states.at(it->first) = game->vk_states[keybind->first];
	}
}

extern "C" int GetKeyboardStateHandler(BYTE* diKeys) {
	for (uint8_t priority = 0; priority <= 4; priority += 1) {
		for (DLL* dll : modDLLs) {
			if (dll->mod->OnGetKeyboardStatePriority == (GenericMod::Priority)priority) {
				UpdateModControlStates(dll->mod);
				dll->mod->OnGetKeyboardState(diKeys);
			}
		}
	}
    return 0;
}

GETTER_VAR(void*, ASM_GetKeyboardStateHandler_jmpback);
void ASM_GetKeyboardStateHandler() {
    asm(".intel_syntax \n"
		// original code
		"mov rcx, qword ptr [rbp-0x50] \n"
		"mov rax, [rcx] \n"
		"lea r8, [rbp+0x480] \n"
		"mov edx, r14d \n"
		"call qword ptr [rax+0x48] \n" // call to the actual function, or at least steam's hook of it.


		PUSH_ALL
		"lea rcx, [rbp+0x480] \n" // diKeys
        PREPARE_STACK

        "call GetKeyboardStateHandler \n"

        RESTORE_STACK
        POP_ALL

        DEREF_JMP(ASM_GetKeyboardStateHandler_jmpback)
       );
}
void SetupGetKeyboardStateHandler() {
    WriteFarJMP(Offset(base, 0x13664B), (void*)&ASM_GetKeyboardStateHandler);
	ASM_GetKeyboardStateHandler_jmpback = Offset(base, 0x13665F);
}
