#pragma once

#include <string>
#include "DLL.h"
#include "CWSDK/modhelper/commands/BaseCommand.h"

/*
* Know if the chat message is a valid command syntax
* if fthe command name is a real loaded command
* check for all the mods that has that command
* 0 mods {
* - return error "No commands"
* } 1 mods {
* - run command
* } more than 1 commands {
* - return error "mods [ModList]"
* }
* allow the player to chose the mod of the command "/mod1 command_name param1 param2"
*/

class CommandsWrapper {
public:
	static bool isCommandSyntaxValid(std::wstring* msg) {
		int pos = msg->find_first_of(L"/");
		if (pos != 0) return false; // if '/' is the first char
		if (msg->size() < 2) return false; // and contains at least an other character
		return true;
	}

	static wchar_t* getCommandName(std::wstring* msg) {
		int space = msg->find_first_not_of(L" ");
		if (space == std::wstring::npos) {
			space = msg->size();
		}

		wchar_t* command_char = L"";
		msg->copy(command_char, 1, space);
		return command_char;
	}

	static BaseCommand* getCommand(wchar_t* command_name, DLL* dll) {
		std::wstring command_string = std::wstring(command_name);
		return dll->mod->cmd_manager.getCommand(&command_string);
	}
};