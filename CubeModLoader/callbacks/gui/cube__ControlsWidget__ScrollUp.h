#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" void cube__ControlsWidget__ScrollUp(cube::ControlsWidget * widget)
{
    widget->scroll_position--;
    if (widget->scroll_position < 0)
        widget->scroll_position = 0;
    widget->UpdateScrollBarPosition();
}

overwrite_function(0x276F10, cube__ControlsWidget__ScrollUp);