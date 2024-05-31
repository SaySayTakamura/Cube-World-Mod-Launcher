#pragma once
#include "../../CWSDK/cwsdk.h"
/*
extern "C" void cube__Game__HandleMouseWheel(cube::Game* game, int mousedata)
{
	cube::InventoryWidget* widget = game->gui.equipment_inventory_widget;

	plasma::Node* node = widget->node;
	if (node->IsVisible() && node->IsMouseOverNode()) {
		if (mousedata >= 0) {
			if (mousedata > 0)
				widget->ScrollUp();
			// Otherwise do nothing
		}
		else {
			widget->ScrollDown();
		}
	}
	return;
}

overwrite_function(0x97CC0, cube__Game__HandleMouseWheel);*/
