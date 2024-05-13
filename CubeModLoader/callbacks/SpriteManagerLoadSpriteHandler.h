#pragma once
#include <string>
#include "cwsdk.h"
#include "../ModWidget.h"

extern "C" void LoadSpriteHandler(cube::SpriteManager* sprite_manager, std::string* string) {
    sprite_manager->LoadSprites();
    //((void(*)(cube::SpriteManager*, std::string))CWOffset(0x177F50))(sprite_manager, *string);
    //string->append(string->c_str());
}

GETTER_VAR(void*, ASMLoadSpriteHandler_jmpback);
void ASMLoadSpriteHandler() {
    asm(".intel_syntax \n"
		PUSH_ALL

        "mov rdx, [rsp+38] \n"
        "mov rcx, rdi \n"
		
        PREPARE_STACK

        "call LoadSpriteHandler \n"

        RESTORE_STACK

        POP_ALL

		DEREF_JMP(ASMLoadSpriteHandler_jmpback)
       );
}
void SetupLoadSpriteHandler() {
    WriteFarJMP(Offset(base, 0x173012), (void*)&ASMLoadSpriteHandler);
    ASMLoadSpriteHandler_jmpback = Offset(base, 0x173020);
}
