#pragma once
#include <string>
#include "cwsdk.h"
#include "../ModWidget.h"

void InitUI(cube::Game* game)
{
	// Variables
	FloatVector2 size(500, 150);
	std::wstring name(L"mod-node");
	std::wstring w_name(L"mod-widget");

	// Create node to add to the engine root node (automatically gets drawn)
	plasma::Node* node = game->plasma_engine->CreateNode(game->plasma_engine->root_node, &name);
	
	// Create a deep copy of the blackwidget (background node)
	plasma::Node* background = game->gui.blackwidget_node_0->CreateDeepCopy(node);
	background->widget1->SetSize(&size);
	background->widget1->field_1A0 = 0;

	mod::ModWidget::Init();
	mod::ModWidget* widget = (mod::ModWidget*)new char[sizeof(mod::ModWidget)];

	// Create a widget and add it to the node specified.
	widget->ctor(game, node);
}

extern "C" void GameTickHandler(cube::Game* game) {
	static bool init = false;
	if (!init)
	{
		init = true;

		InitUI(game);

		// Create deep copy of the cursor node
		plasma::Node* node = game->gui.cursor_node->CreateDeepCopy(game->plasma_engine->root_node);

		// Hide the old cursor node
		game->gui.cursor_node->SetVisibility(false);

		// Set the new cursor node
		game->gui.cursor_node = node;
	}

	for (uint8_t priority = 0; priority <= 4; priority += 1) {
		for (DLL* dll : modDLLs) {
			if (dll->mod->OnGameTickPriority == (GenericMod::Priority)priority) {
				dll->mod->OnGameTick(game);
			}
		}
	}
}

GETTER_VAR(void*, ASMGameTickHandler_jmpback);
void ASMGameTickHandler() {
    asm(".intel_syntax \n"
		PUSH_ALL

        "mov rcx, rax \n" // cube::Game*

        PREPARE_STACK

        "call GameTickHandler \n"

        RESTORE_STACK

        POP_ALL

        // original code
        "mov [rsp+0x20], ebx \n"
        "xor r9d, r9d \n"
        "xor r8d, r8d \n"
		"xor edx, edx \n"
		"lea rcx, [rbp+0xB8] \n"

		DEREF_JMP(ASMGameTickHandler_jmpback)
       );
}
void SetupGameTickHandler() {
    WriteFarJMP(Offset(base, 0x136458), (void*)&ASMGameTickHandler);
	ASMGameTickHandler_jmpback = Offset(base, 0x13646B);
}
