#pragma once
#include "../../CWSDK/cwsdk.h"

// TODO: replace ids when Helper mapping will work.
uint64_t GetConsumableItemModel(cube::Item* item) {
	uint64_t result = 0;
	switch (item->id) {
	case 0:
		result = 1046LL; break;
	case 1:
		result = 1039LL + item->rarity; break;
	case 2:
		result = 1044LL; break;
	case 3:
		result = 1045LL; break;
	case 4:
		result = 3269LL; break;
	case 7:
		result = 2791LL; break;
	case 8:
		result = 3267LL; break;
	case 9:
		result = 3488LL; break;
	case 10:
		result = 3201LL; break;
	case 11:
		result = 3198LL; break;
	case 13:
		result = 3628LL; break;
	case 14:
		result = 3280LL; break;
	default:
		result = 1030LL; break;
	}
	return result;
}

uint64_t GetWeaponItemModel(cube::Item* item) {
	uint64_t result = 0;
	int rarity = min(max(item->rarity, 0), 4);
	int modifier = item->modifier % 0xB;
	int modifier6 = item->modifier % 0x6;
	switch (item->id) {
	case 0:
		switch (item->material) {
		case 5:
			result = 2292LL;
			break;
		case 7:
			result = 2292LL;
			break;
		default:
			result = rarity + 1106LL + 5 * modifier;
			break;
		}
		break;
	case 1:
		switch (item->material) {
		case 5:
			result = 2293LL;
			break;
		case 7:
			result = 2307LL;
			break;
		default:
			result = rarity + 2002LL + 5 * modifier;
			break;
		}
		break;
	case 2:
		switch (item->material) {
		case 2:
			result = 847LL + rarity;
			break;
		case 7:
			result = 2307LL;
			break;
		default:
			result = rarity + 2002LL + 5 * modifier;
			break;
		}
		break;
	case 3:
		result = rarity + 1161LL + 5 * modifier;
		break;
	case 4:
		result = rarity + 1216LL + 5 * modifier;
		break;
	case 5:
		switch (item->material) {
		case 5:
			result = 2169LL;
			break;
		default:
			result = rarity + 2112LL + 5 * modifier;
			break;
		}
		break;
	case 6:
		result = rarity + 859LL + 5 * modifier;
		break;
	case 7:
		result = rarity + 914LL + 5 * modifier;
		break;
	case 8:
		result = rarity + 969LL + 5 * modifier;
		break;
	case 9:
		result = 1025LL;
		break;
	case 10: {
		int m = item->material - 4;
		if (m != 0) {
			if (m - 1 != 0) {
				if (m - 1 == 39) {
					result = 858LL;
				}
				else {
					result = rarity + 617LL + 5 * modifier;
				}
			}
			else {
				result = 787LL + rarity;
			}
		}
		else {
			result = 2408LL;
		}
		break;
	}
	case 11:
		result = rarity + 672LL + 5 * modifier;
		break;
	case 12:
		switch (item->material) {
		case 11:
			result = rarity + 727LL + 5 * modifier6;
			break;
		default:
			result = rarity + 757LL + 5 * modifier6;
			break;
		}
		break;
	case 13:
		switch (item->material) {
		case 2:
			result = rarity + 1326LL;
			break;
		default:
			result = rarity + 1271LL + 5 * modifier;
			break;
		}
		break;
	case 14:
		result = 1024LL;
		break;
	case 15:
		switch (item->material) {
		case 5:
			result = 2168LL;
			break;
		case 7:
			result = 2167LL;
			break;
		default:
			result = rarity + 2057LL + 5 * modifier;
			break;
		}
		break;
	case 16:
		switch (item->material) {
		case 5:
			result = 2226LL;
			break;
		case 7:
			result = 2225LL;
			break;
		case 19:
			result = 2227LL;
			break;
		default:
			result = rarity + 5 * (modifier+434LL);
			break;
		}
		break;
	case 17:
		switch (item->material) {
		case 2:
			result = 2228LL;
			break;
		case 5:
			result = 2286LL;
			break;
		case 7:
			result = 2285LL;
			break;
		default:
			result = rarity + 2229LL + 5 * modifier;
			break;
		}
		break;
	case 18:
		result = 3195LL;
		break;
	case 19:
		result = 2284LL;
		break;
	case 20:
		result = 1029LL;
		break;
	case 21:
		result = 3620LL;
		break;
	default:
		result = 1106LL;
		break;
	}
	return result;
}

extern "C" cube::Sprite* cube__SpriteManager__GetItemModelSprite(cube::SpriteManager * sprite_manager, cube::Item * original_item)
{
	cube::Item item;
	((void(*)(cube::Item*, cube::Item*))CWOffset(0x1092B0))(original_item, &item); // copy item, but change things for item 0x16 quest items
	switch (item.category) {
	case 0x01: {
		uint64_t id = GetConsumableItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		return sprite_manager->sprites.at(id);
	}
	case 0x02: {
		uint64_t id = 3306LL; 
		if (id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		return sprite_manager->sprites.at(id);
	}
	case 0x03: {
		uint64_t id = GetWeaponItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case 0x0F: // leftover
		return sprite_manager->sprites.at(max(min(original_item->rarity-1, 3), 0) + 3182);
	default:
		return nullptr; //sprite_manager->sprites.at(3121LL);
	}
};

overwrite_function(0x173B10, cube__SpriteManager__GetItemModelSprite);