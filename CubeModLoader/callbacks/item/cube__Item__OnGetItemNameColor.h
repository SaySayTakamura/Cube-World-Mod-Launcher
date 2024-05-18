#pragma once
#include "../../CWSDK/cwsdk.h"

FloatRGBA* GetItemRarityColor(FloatRGBA* color, int rarity) {
    int r = min(max(rarity, -1), 4);
    switch (r)
    {
    case -1:
        color->red = 0.70f;
        color->green = 0.70f;
        color->blue = 0.70f;
        color->alpha = 1.00f;
        break;
    case 0:
        color->red = 1.00f;
        color->green = 1.00f;
        color->blue = 1.00f;
        color->alpha = 1.00f;
        break;
    case 1:
        color->red = 0.00f;
        color->green = 1.00f;
        color->blue = 0.00f;
        color->alpha = 1.00f;
        break;
    case 2:
        color->red = 0.30f;
        color->green = 0.45f;
        color->blue = 1.00f;
        color->alpha = 1.00f;
        break;
    case 3:
        color->red = 0.55f;
        color->green = 0.20f;
        color->blue = 1.00f;
        color->alpha = 1.00f;
        break;
    case 4:
        color->red = 1.00f;
        color->green = 1.00f;
        color->blue = 0.00f;
        color->alpha = 1.00f;
        break;
    default:
        color->red = 1.00f;
        color->green = 0.20f;
        color->blue = 0.20f;
        color->alpha = 1.00f;
        break;
    }
    return color;
}

FloatRGBA* GetItemNameColor(cube::Item* item, FloatRGBA* color, IntVector2* region_position) {
    unsigned int category = item->category;
    const long v6 = 010400101774;

    if ((category - 23) <= 1u)
    {
        color->red = 1.0;
        color->green = 0.60000002;
        color->blue = 0.25;
        color->alpha = 1.0;
        return color;
    }
    switch (category)
    {
    case 0x15:
        color->red = 0.69999999;
        color->green = 1.0;
        color->blue = 0.25;
        color->alpha = 1.0;
        return color;
    case 0:
        color->red = 1.0;
        color->green = 1.0;
        color->blue = 1.0;
        color->alpha = 1.0;
        return color;
    case 0x16:
        color->red = 0.5;
        color->green = 1.0;
        color->blue = 1.0;
        color->alpha = 1.0;
        return color;
    case 0xD:
        color->red = 0.5;
        color->green = 0.1;
        color->blue = 1.0;
        color->alpha = 1.0;
        return color;
    }
    if (category == 1 && item->id == 13)
    {
        color->red = 0.5;
        color->green = 1.0;
        color->blue = 1.0;
        color->alpha = 1.0;
        return color;
    }
    if (category <= 30u && _bittest(&v6, category)) // v6 is 01000111101000000010000000010100 each number from right to left is a boolean for each category.
    {
        GetItemRarityColor(color, item->GetEffectiveRarity(region_position));
        return color;
    }
    else
    {
        GetItemRarityColor(color, item->rarity);
        return color;
    }
}

extern "C" FloatRGBA* cube__Item__OnGetItemNameColor(cube::Item * item, FloatRGBA * color, IntVector2* region_position)
{
	for (DLL* dll : modDLLs) {
		modhelper::ItemManager* item_manager = &dll->mod->item_manager;
		if (item_manager->Exists((cube::Item::CategoryType)item->category, item->id))
		{
			modhelper::ItemData* item_data = item_manager->Get((cube::Item::CategoryType)item->category, item->id);
			if (item_data != nullptr) {
				FloatRGBA* color = item_data->itemBehaviour->GetNameColor(item);
                if (color != nullptr) {
                    return color;
                }
			}
		}
	}

	return GetItemNameColor(item, color, region_position);
}

overwrite_function(0x10A600, cube__Item__OnGetItemNameColor)