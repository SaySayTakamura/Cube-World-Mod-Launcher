#pragma once
#include "../../CWSDK/cwsdk.h"

uint64_t GetConsumableUseTime(cube::Item* item) {
    // Elixir
    if (item->category == 28)
    {
        return 500LL;
    }

    if (item->category != 1)
    {
        return 0LL;
    }

    if (item->id != 1)
    {
        if (item->id == 2)
            return (1.5 - ((item->rarity * 0.5) * 0.25)) * 6000.0;
        if (item->id == 3)
            return 500LL;
        if (item->id != 12)
            return (1.5 - ((item->rarity * 0.5) * 0.25)) * 10000.0;
    }

    // Potions ?
    return (1.5 - ((item->rarity * 0.5) * 0.25)) * 5000.0;
}

extern "C" int cube__Item__OnGetConsumableUseTime(cube::Item * item)
{
	for (DLL* dll : modDLLs) {
		modhelper::ItemManager* item_manager = &dll->mod->item_manager;
		if (item_manager->Exists((cube::Item::CategoryType)item->category, item->id))
		{
			modhelper::ItemData* item_data = item_manager->Get((cube::Item::CategoryType)item->category, item->id);
			if (item_data != nullptr) {
				return item_data->itemBehaviour->GetConsumableUseTime(item);
			}
		}
	}

	return GetConsumableUseTime(item);
}

overwrite_function(0x108FA0, cube__Item__OnGetConsumableUseTime)