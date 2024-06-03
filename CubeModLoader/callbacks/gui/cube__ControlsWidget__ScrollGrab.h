#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" plasma::D3D11Engine * cube__ControlsWidget__ScrollGrab(cube::ControlsWidget * widget)
{
    int keys_size = 23;

    for (DLL* dll : modDLLs) {
        keys_size += dll->mod->keybind_manager.GetKeybinds()->size();
    }

    plasma::D3D11Engine* engine = widget->d3d11_engine;
    if ((engine->gap194[20] & 1) != 0)
    {
        int v3 = ((widget->GetYSize() - 150.0) - 35.0);
        float v4 = ((float (*)(plasma::Widget*))CWOffset(0x32AD10))(widget->scrollbutton->widget1);
        FloatVector2 v12;
        FloatVector2 v13;
        FloatVector2* v5 = ((FloatVector2 * (*)(plasma::Widget*, FloatVector2*))CWOffset(0x329F50))(widget->scrollbutton->widget1, &v13);
        FloatVector2* v6 = ((FloatVector2 * (*)(plasma::Widget*, FloatVector2*))CWOffset(0x32B0D0))(widget, &v12); // OnGrabScrollBarMaybe
        int v7 = (2290649225LL * v3) >> 32;
        float v8 = v3 - v4;
        int v9 = (v7 >> 31) + (v7 >> 4);
        float v10 = fminf((v8 + 35), fmaxf(35.0, v6->y + v5->y));
        if (v8 > 0)
            widget->scroll_position = ((((keys_size-1) - v9) * (v10 - 35.0)) / v8);
        if (widget->scroll_position < 0)
            widget->scroll_position = 0;
        if (widget->scroll_position >= keys_size - v9)
            widget->scroll_position = (keys_size-1) - v9;
        FloatVector2* v11 = ((FloatVector2 * (*)(plasma::Widget*, FloatVector2*))CWOffset(0x329F50))(widget->scrollbutton->widget1, &v12);
        ((FloatVector2* (*)(plasma::Widget*, float, float, bool))CWOffset(0x32B560))(widget->scrollbutton->widget1, v11->x, v10, 1);
    }
    return engine;
}

overwrite_function(0x276AF0, cube__ControlsWidget__ScrollGrab);