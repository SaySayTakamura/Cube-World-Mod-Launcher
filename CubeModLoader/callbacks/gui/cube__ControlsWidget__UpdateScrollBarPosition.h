#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" void cube__ControlsWidget__UpdateScrollBarPosition(cube::ControlsWidget * widget)
{
    int keys_size = 23;

    for (DLL* dll : modDLLs) {
        keys_size += dll->mod->keybind_manager.GetKeybinds()->size();
    }
    keys_size++;

    if (widget->scrollbutton)
    {
        float v2 = ((widget->GetYSize() - 150.0) - 35.0);
        cube::BaseWidget* widget1 = (cube::BaseWidget*)widget->scrollbutton->widget1;
        float XSize = widget1->GetXSize();
        float v5 = (widget->scroll_position * (v2 - v2 * (v2 / 30) / keys_size) / ((keys_size - 1) - v2 / 30) + 35);
        float v6 = widget->GetXSize();
        FloatVector2 pos = { v6 - 28.0f, v5 };
        FloatVector2 pos2 = { XSize, (v2 * (v2 / 30) / keys_size) };
        ((float* (*)(plasma::Widget*, FloatVector2*, int))CWOffset(0x32B250))(widget1, &pos, 0);
        //widget1->TranslateBase(&pos, 0);
        widget1->Translate(&pos2, 1);
    }
}

overwrite_function(0x276F40, cube__ControlsWidget__UpdateScrollBarPosition);