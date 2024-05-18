#pragma once
#include "../CWSDK/cwsdk.h"

extern "C" void GetItemNameHandler(cube::Item * item, std::wstring * string)
{
	for (DLL* dll : modDLLs) {
		modhelper::ItemManager* item_manager = &dll->mod->item_manager;
		if (item_manager->Exists((cube::Item::CategoryType)item->category, item->id))
		{
			modhelper::ItemData* item_data = item_manager->Get((cube::Item::CategoryType)item->category, item->id);
			if (item_data != nullptr) {
				std::wstring* result = item_data->itemBehaviour->GetDisplayName(item);
				if (result == nullptr) continue;

				*string = *result;
				return;
			}
		}
	}
}

// ASM code from Nichiren in the PyroProgression mod.
__attribute__((naked)) void ASM_GetItemNameHandler() {
	asm(".intel_syntax \n"
		// rdi: item
		// rsi: wstring
		"mov rdx, rsi \n"
		"lea rcx, [rbp + 0x60] \n"
		"call GetItemNameHandler \n"

		// Old code
		"mov rax, rsi \n"
		"mov rcx, [rbp + 0x280] \n"
		"xor rcx, rsp \n"
		"mov rbx, [rsp + 0x3C8] \n"
		"add rsp, 0x390 \n"
		"pop rdi \n"
		"pop rsi \n"
		"pop rbp \n"
		"retn \n"
	);
}

void SetupGetItemNameHandler() {
	WriteFarJMP(CWOffset(0x16466C), (void*)&ASM_GetItemNameHandler);
}