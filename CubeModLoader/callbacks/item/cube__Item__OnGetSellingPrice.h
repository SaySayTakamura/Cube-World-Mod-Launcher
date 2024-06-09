#pragma once
#include "../../CWSDK/cwsdk.h"

extern "C" int cube__Item__OnGetSellingPrice(cube::Item* item)
{
	int buyingPrice = item->GetBuyingPrice();
	int sellingPrice = std::max<float>(0.5f * std::sqrt(buyingPrice), 1);

	for (uint8_t priority = 0; priority <= 4; priority += 1) {
		for (DLL* dll : modDLLs) {
			if (dll->mod->OnGetItemSellingPricePriority == (GenericMod::Priority)priority) {
				dll->mod->OnGetItemSellingPrice(item, &sellingPrice);
			}

			modhelper::ItemData* item_data = dll->mod->item_manager.Get((cube::Item::CategoryType)item->category, item->id);
			if (item_data == nullptr) continue;
			int price = item_data->itemBehaviour->GetSellingPrice(item);
			if (price <= 0) continue;
			return price;
		}
	}

	return sellingPrice;
}

overwrite_function(0x10A390, cube__Item__OnGetSellingPrice)