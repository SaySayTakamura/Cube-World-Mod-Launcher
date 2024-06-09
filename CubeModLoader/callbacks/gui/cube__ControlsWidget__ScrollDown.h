#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" void cube__ControlsWidget__ScrollDown(cube::ControlsWidget * widget)
{
    int keys_size = 23;
    
    for (DLL* dll : modDLLs) {
        keys_size += dll->mod->keybind_manager.GetKeybinds()->size();
    }

    float YSize = widget->GetYSize();
    widget->scroll_position++;
    int maxSize = ((YSize - 150.0) - 35.0) / 30;
    if (widget->scroll_position >= keys_size - maxSize)
        widget->scroll_position = (keys_size-1) - maxSize;

    widget->UpdateScrollBarPosition();
}

overwrite_function(0x276EA0, cube__ControlsWidget__ScrollDown);