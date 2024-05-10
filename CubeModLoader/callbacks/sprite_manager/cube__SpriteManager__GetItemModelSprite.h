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

uint64_t GetScrollItemModel(cube::Item* item) {
	return 3306LL;
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

uint64_t GetArmorShouldersItemModel(cube::Item* item) {
	int rarity = min(max(item->rarity, 0), 4);

	switch (item->material) {
	case cube::Item::MaterialType::Steel:
		return rarity + 2393LL;
	case cube::Item::MaterialType::Obsidian:
		return 2288LL;
	case cube::Item::MaterialType::Bone:
		return 2301LL;
	case cube::Item::MaterialType::Gold:
		return 2296L;
	case cube::Item::MaterialType::Saurian:
		return 1432LL;
	case cube::Item::MaterialType::Parrot:
		return 3238LL;
	case cube::Item::MaterialType::Mammoth:
		return 3244LL;
	case cube::Item::MaterialType::Ice:
		return 3225LL;
	case cube::Item::MaterialType::Light:
		return 854LL;
	case cube::Item::MaterialType::Silk:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1926LL) + rarity;
	case cube::Item::MaterialType::Linnen:
		return item->modifier % 5 + (4 * (item->modifier % 5 + 404LL)) + rarity;
	case cube::Item::MaterialType::Cotton:
		return item->modifier % 5 + (4 * (item->modifier % 5 + 429LL)) + rarity;
	case cube::Item::MaterialType::Bronze:
		return rarity + 2313LL;
	case cube::Item::MaterialType::Calcio:
		return rarity + 2333LL;
	case cube::Item::MaterialType::Felt:
		return rarity + 2353LL;
	case cube::Item::MaterialType::Flannell:
		return rarity + 2373LL;
	case cube::Item::MaterialType::Mail:
		return rarity + 2414LL;
	case cube::Item::MaterialType::Rivet:
		return rarity + 2434LL;
	case cube::Item::MaterialType::Filament:
		return rarity + 2454LL;
	case cube::Item::MaterialType::Spike:
		return rarity + 2474LL;
	case cube::Item::MaterialType::Fiber:
		return rarity + 2494LL;
	case cube::Item::MaterialType::Scale:
		return rarity + 2514LL;
	case cube::Item::MaterialType::Web:
		return rarity + 2534LL;
	case cube::Item::MaterialType::Shadow:
		return rarity + 2554LL;
	case cube::Item::MaterialType::Dark:
		return rarity + 2574LL;
	case cube::Item::MaterialType::Demon:
		return rarity + 2614LL;
	case cube::Item::MaterialType::Fire:
		return rarity + 2594LL;
	default:
		return item->modifier % 5 + (4 * (item->modifier % 5 + 339LL)) + rarity;
	}
}

uint64_t GetArmorChestItemModel(cube::Item* item) {
	if (item->id == 1)
		return 0LL;

	int rarity = min(max(item->rarity, 0), 4);

	switch (item->material) {
	case cube::Item::MaterialType::Steel:
		return 2388LL + rarity;
	case cube::Item::MaterialType::Obsidian:
		return 2287LL;
	case cube::Item::MaterialType::Cloth: {
		/*if (item->id <= 6) {
			return 1436 + item->id;
		}
		return GetArmorShouldersItemModel(item);*/ // Same code but more compact
		switch (item->id) {
		case 0:
			return 1436LL;
		case 1:
			return 1437LL;
		case 2:
			return 1438LL;
		case 3:
			return 1439LL;
		case 4:
			return 1440LL;
		case 5:
			return 1441LL;
		case 6:
			return 1442LL;
		default: // LABEL_177
			return GetArmorShouldersItemModel(item);
		}
	}
	case cube::Item::MaterialType::Bone:
		return 2300LL;
	case cube::Item::MaterialType::Gold:
		return 2295LL;
	case cube::Item::MaterialType::Saurian:
		return 1431LL;
	case cube::Item::MaterialType::Parrot:
		return 3235LL;
	case cube::Item::MaterialType::Ice:
		return 3226LL;
	case cube::Item::MaterialType::Light:
		return 853LL;
	case cube::Item::MaterialType::Silk:
		return 5 * (item->modifier % 5) + (rarity + 1901LL);
	case cube::Item::MaterialType::Linnen:
		return 5 * (item->modifier % 5) + (rarity + 1591LL);
	case cube::Item::MaterialType::Cotton:
		return 5 * (item->modifier % 5) + (rarity + 1691LL);
	case cube::Item::MaterialType::Bronze:
		return rarity + 2308LL;
	case cube::Item::MaterialType::Calcio:
		return rarity + 2328LL;
	case cube::Item::MaterialType::Felt:
		return rarity + 2348LL;
	case cube::Item::MaterialType::Flannell:
		return rarity + 2368LL;
	case cube::Item::MaterialType::Mail:
		return rarity + 2409LL;
	case cube::Item::MaterialType::Rivet:
		return rarity + 2429LL;
	case cube::Item::MaterialType::Filament:
		return rarity + 2449LL;
	case cube::Item::MaterialType::Spike:
		return rarity + 2469LL;
	case cube::Item::MaterialType::Fiber:
		return rarity + 2489LL;
	case cube::Item::MaterialType::Scale:
		return rarity + 2509LL;
	case cube::Item::MaterialType::Web:
		return rarity + 2529LL;
	case cube::Item::MaterialType::Shadow:
		return rarity + 2549LL;
	case cube::Item::MaterialType::Dark:
		return rarity + 2569LL;
	case cube::Item::MaterialType::Demon:
		return rarity + 2609LL;
	case cube::Item::MaterialType::Fire:
		return rarity + 2589LL;
	case cube::Item::MaterialType::Druid:
		return 857LL;
	default:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1331LL) + rarity;
	}
}

uint64_t GetArmorGlovesItemModel(cube::Item* item) {
	int rarity = min(max(item->rarity, 0), 4);

	switch (item->material) {
	case cube::Item::MaterialType::Iron:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1381LL) + rarity;
	case cube::Item::MaterialType::Steel:
		return rarity + 2403LL;
	case cube::Item::MaterialType::Obsidian:
		return 2290LL;
	case cube::Item::MaterialType::Bone:
		return 2303LL;
	case cube::Item::MaterialType::Gold:
		return 2298LL;
	case cube::Item::MaterialType::Saurian:
		return 1433LL;
	case cube::Item::MaterialType::Parrot:
		return 3234LL;
	case cube::Item::MaterialType::Mammoth:
		return 3240LL;
	case cube::Item::MaterialType::Ice:
		return 3228LL;
	case cube::Item::MaterialType::Light:
		return 855LL;
	case cube::Item::MaterialType::Silk:
		return item->modifier % 5 + 4 * (item->modifier % 5 + 494LL) + rarity;
	case cube::Item::MaterialType::Linnen:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1666LL) + rarity;
	case cube::Item::MaterialType::Cotton:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1766LL) + rarity;
	case cube::Item::MaterialType::Bronze:
		return rarity + 2323LL;
	case cube::Item::MaterialType::Calcio:
		return rarity + 2343LL;
	case cube::Item::MaterialType::Felt:
		return rarity + 2363LL;
	case cube::Item::MaterialType::Flannell:
		return rarity + 2383LL;
	case cube::Item::MaterialType::Mail:
		return rarity + 2424LL;
	case cube::Item::MaterialType::Rivet:
		return rarity + 2444LL;
	case cube::Item::MaterialType::Filament:
		return rarity + 2464LL;
	case cube::Item::MaterialType::Spike:
		return rarity + 2484LL;
	case cube::Item::MaterialType::Fiber:
		return rarity + 2504LL;
	case cube::Item::MaterialType::Scale:
		return rarity + 2524LL;
	case cube::Item::MaterialType::Web:
		return rarity + 2544LL;
	case cube::Item::MaterialType::Shadow:
		return rarity + 2564LL;
	case cube::Item::MaterialType::Dark:
		return rarity + 2584LL;
	case cube::Item::MaterialType::Demon:
		return rarity + 2624LL;
	case cube::Item::MaterialType::Fire:
		return rarity + 2604LL;
	default:
		return 18LL;
	}
}

uint64_t GetArmorBootsItemModel(cube::Item* item) {
	int rarity = min(max(item->rarity, 0), 4);

	switch (item->material) {
	case cube::Item::MaterialType::Iron:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1406LL) + rarity;
	case cube::Item::MaterialType::Steel:
		return rarity + 2398LL;
	case cube::Item::MaterialType::Obsidian:
		return 2289LL;
	case cube::Item::MaterialType::Bone:
		return 2302LL;
	case cube::Item::MaterialType::Gold:
		return 2297L;
	case cube::Item::MaterialType::Saurian:
		return 1434LL;
	case cube::Item::MaterialType::Parrot:
		return 3236LL;
	case cube::Item::MaterialType::Mammoth:
		return 3242LL;
	case cube::Item::MaterialType::Ice:
		return 3227LL;
	case cube::Item::MaterialType::Light:
		return 856LL;
	case cube::Item::MaterialType::Silk:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1951LL) + rarity;
	case cube::Item::MaterialType::Linnen:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1641LL) + rarity;
	case cube::Item::MaterialType::Cotton:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1741LL) + rarity;
	case cube::Item::MaterialType::Bronze:
		return rarity + 2318LL;
	case cube::Item::MaterialType::Calcio:
		return rarity + 2338LL;
	case cube::Item::MaterialType::Felt:
		return rarity + 2358LL;
	case cube::Item::MaterialType::Flannell:
		return rarity + 2378LL;
	case cube::Item::MaterialType::Mail:
		return rarity + 2419LL;
	case cube::Item::MaterialType::Rivet:
		return rarity + 2439LL;
	case cube::Item::MaterialType::Filament:
		return rarity + 2459LL;
	case cube::Item::MaterialType::Spike:
		return rarity + 2479LL;
	case cube::Item::MaterialType::Fiber:
		return rarity + 2499LL;
	case cube::Item::MaterialType::Scale:
		return rarity + 2519LL;
	case cube::Item::MaterialType::Web:
		return rarity + 2539LL;
	case cube::Item::MaterialType::Shadow:
		return rarity + 2559LL;
	case cube::Item::MaterialType::Dark:
		return rarity + 2579LL;
	case cube::Item::MaterialType::Demon:
		return rarity + 2619LL;
	case cube::Item::MaterialType::Fire:
		return rarity + 2599LL;
	default:
		return 616LL;
	}
}

uint64_t GetAmuletItemModel(cube::Item* item) {
	int rarity = min(max(item->rarity, 0), 4);

	switch (item->material) {
	case cube::Item::MaterialType::Silver:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1826LL) + rarity;
	default:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 449LL) + rarity;
	}
}

uint64_t GetRingItemModel(cube::Item* item) {
	int rarity = min(max(item->rarity, 0), 4);

	switch (item->material) {
	case cube::Item::MaterialType::Silver:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 169LL) + rarity;
	default:
		return item->modifier % 5 + (4 * (item->modifier % 5) + 1851LL) + rarity;
	}
}

uint64_t GetUnknownVoxelItemModel(cube::Item* item) {
	return 2630LL;
}

uint64_t GetCollectibleItemModel(cube::Item* item) {
	switch (item->id) {
	case 0:
		switch (item->material) {
		case cube::Item::MaterialType::Iron:
			return 3203LL;
		case cube::Item::MaterialType::Wood:
			return 3231LL;
		case cube::Item::MaterialType::Gold:
			return 3205LL;
		case cube::Item::MaterialType::Silver:
			return 3204LL;
		case cube::Item::MaterialType::Emerald:
			return 3206LL;
		case cube::Item::MaterialType::Sapphire:
			return 3207LL;
		case cube::Item::MaterialType::Ruby:
			return 3208LL;
		case cube::Item::MaterialType::Diamond:
			return 3209LL;
		case cube::Item::MaterialType::Sandstone:
			return 3230LL;
		default:
			return 0LL;
		}
	case 1:
		return 3231LL;
	case 2:
		return 3232LL;
	case 5:
		return 3268LL;
	case 6:
		return 3218LL;
	case 7:
		return 3239LL;
	case 8:
		return 3223LL;
	case 9:
		return 3229LL;
	case 10:
		switch (item->material) {
		case cube::Item::MaterialType::Iron:
			return 3210LL;
		case cube::Item::MaterialType::Wood:
			return 3213LL;
		case cube::Item::MaterialType::Gold:
			return 3212LL;
		case cube::Item::MaterialType::Silver:
			return 3211LL;
		default:
			return 0LL;
		}
	case 11:
		return 2879LL;
	case 12:
		return 3263LL;
	case 13:
		return 3202LL;
	case 14:
		switch (item->material) {
		case cube::Item::MaterialType::UnholySpirit:
			return 3216LL;
		case cube::Item::MaterialType::IceSpirit:
			return 3215LL;
		case cube::Item::MaterialType::WindSpirit:
			return 3217LL;
		default:
			return 3214LL;
		}
	case 15:
		return 1030LL;
	case 16:
		return 3196LL;
	case 17:
		return 3200LL;
	case 18:
		return 3265LL;
	case 19:
		return 1031LL;
	case 20:
		return 2798LL;
	case 21:
		return 2766LL;
	case 22:
		return 1034LL;
	case 23:
		return 1033LL;
	case 24:
		return 1032LL;
	case 25:
		return 1038LL;
	case 26:
		return 3264LL;
	case 27:
		return 2790LL;
	case 28:
		return 1035LL;
	case 29:
		return 1036LL;
	case 30:
		return 1037LL;
	case 31:
		return 3199LL;
	case 32:
		return 3206LL;
	case 33:
		return 3207LL;
	case 34:
		return 3208LL;
	case 35:
		return 3209LL;
	case 36:
		return 3648LL;
	case 37:
		return 3649LL;
	case 38:
		return 3275LL;
	case 39:
		return 3215LL;
	case 40:
		return 3276LL;
	case 41:
		return 3277LL;
	case 42:
		return 3278LL;
	case 43:
		return 3279LL;
	default:
		return 0;
	}
}

uint64_t GetCoinItemModel(cube::Item* item) {
	switch (item->material) {
	case cube::Item::MaterialType::Gold:
		return 2785LL;
	case cube::Item::MaterialType::Silver:
		return 2784LL;
	case cube::Item::MaterialType::Platinum:
		return 2783LL;
	default:
		return 0LL;
	}
}

uint64_t GetPlatinumCoinItemModel(cube::Item* item) {
	return 3223LL;
}

uint64_t GetManaCubeItemModel(cube::Item* item) {
	return 3510LL;
}

uint64_t GetLeftoverItemModel(cube::Item* item) {
	return max(min(item->rarity - 1, 3), 0) + 3182LL;
}

uint64_t GetBeakItemModel(cube::Item* item) {
	return 3233LL;
}

uint64_t GetPaintingItemModel(cube::Item* item) {
	return (item->modifier & 3) + 3122LL;
}

uint64_t GetVaseItemModel(cube::Item* item) {
	return (item->modifier & 3) + 2832LL;
}

uint64_t GetCandleItemModel(cube::Item* item) {
	int modifier = item->modifier % 3;
	if (item->id == 1) {
		return modifier + 2839LL;
	}
	else {
		return modifier + 2836LL;
	}
}

uint64_t GetPetCageItemModel(cube::Item* item) {
	switch (item->id) {
	case 24:
		return 2889LL;
	case 25:
		return 2880LL;
	default:
		return 2635LL;
	}
}

uint64_t GetPetFoodItemModel(cube::Item* item) {
	if (item->id >= 293) {
		switch (item->id) {
		case 294:
			return 1069LL;
		case 295:
			return 1070LL;
		case 293:
			return 1068LL;
		default:
			return 3200LL;
		}
	}
	else {
		switch (item->id) {
		case 19:
			return 1075LL;
		case 22:
			return 1065LL;
		case 23:
			return 1066LL;
		case 25:
			return 1077LL;
		case 26:
			return 1079LL;
		case 27:
			return 1071LL;
		case 30:
			return 1056LL;
		case 33:
			return 1052LL;
		case 34:
			return 1060LL;
		case 35:
			return 1051LL;
		case 36:
			return 1089LL;
		case 37:
			return 1047LL;
		case 38:
			return 1048LL;
		case 39:
			return 1050LL;
		case 40:
			return 1049LL;
		case 50:
			return 1067LL;
		case 53:
			return 1061LL;
		case 55:
			return 1076LL;
		case 56:
			return 1062LL;
		case 57:
			return 1090LL;
		case 58:
			return 1091LL;
		case 59:
			return 1092LL;
		case 60:
			return 1094LL;
		case 61:
			return 1095LL;
		case 62:
			return 1096LL;
		case 63:
			return 1084LL;
		case 64:
			return 1086LL;
		case 65:
			return 1087LL;
		case 66:
			return 1085LL;
		case 67:
			return 1074LL;
		case 74:
			return 1088LL;
		case 75:
			return 1078LL;
		case 86:
			return 1080LL;
		case 87:
			return 1059LL;
		case 88:
			return 1097LL;
		case 89:
			return 1101LL;
		case 90:
			return 1063LL;
		case 91:
			return 1064LL;
		case 92:
			return 1057LL;
		case 93:
			return 1058LL;
		case 98:
			return 1082LL;
		case 99:
			return 1081LL;
		case 102:
			return 3293LL;
		case 103:
			return 1098LL;
		case 104:
			return 1072LL;
		case 105:
			return 1073LL;
		case 106:
			return 1083LL;
		case 151:
			return 1099LL;
		case 156:
			return 1100LL;
		case 170:
			return 1053LL;
		case 192:
			return 1102LL;
		case 193:
			return 1103LL;
		case 200:
			return 1104LL;
		case 201:
			return 1105LL;
		case 210:
			return 1093LL;
		default:
			return 3200LL;
		}
	}
}

uint64_t GetQuestItemModel(cube::Item* item) {
	switch (item->id) {
	case 0:
		return 2745LL;
	case 1:
		return 2746LL;
	case 2:
		return 2747LL;
	case 3:
		return 2748LL;
	case 4:
		return 2749LL;
	case 5:
		return 2750LL;
	case 6:
		return 2751LL;
	case 7:
		return 2752LL;
	case 8:
		return 2753LL;
	case 9:
		return 2754LL;
	case 10:
		return 2755LL;
	case 11:
		return 2756LL;
	case 12:
		return 2757LL;
	case 13:
		return 2758LL;
	case 14:
		return 2759LL;
	case 15:
		return 2760LL;
	case 16:
		return 2761LL;
	case 17:
		return 2762LL;
	case 18:
		return 2763LL;
	case 19:
		return 2764LL;
	case 21:
		return 2637LL;
	case 22:
		return 2638LL;
	case 23:
		return (item->modifier % 5) + 2639LL;
	case 24:
		return (item->modifier % 5) + 2644LL;
	case 25:
		return 2649LL;
	case 26:
		return (item->modifier & 1) + 2650LL;
	case 27:
		return (item->modifier % 10) + 2652LL;
	case 28:
		return (item->modifier % 6) + 2662LL;
	case 29:
		return (item->modifier % 3) + 2668LL;
	case 30:
		return 2683LL;
	case 31:
		return 2684LL;
	case 32:
		return 2685LL;
	case 33:
		return 2686LL;
	case 34:
		return 2687LL;
	case 35:
		return 2688LL;
	case 36:
		return 2689LL;
	case 37:
		return 2690LL;
	case 38:
		return 2691LL;
	case 39:
		return (item->modifier & 3) + 2692LL;
	case 40:
		return 2696LL;
	case 41:
		return 2697LL;
	case 42:
		return 2698LL;
	case 43:
		return 2699LL;
	case 44:
		return 2700LL;
	case 45:
		return (item->modifier & 3) + 2701LL;
	case 46:
		return (item->modifier & 3) + 2705LL;
	case 47:
		return (item->modifier & 3) + 2709LL;
	case 48:
		return (item->modifier & 3) + 2713LL;
	case 49:
		return (item->modifier & 3) + 2717LL;
	case 50:
		return (item->modifier & 3) + 2721LL;
	case 51:
		return (item->modifier & 3) + 2725LL;
	case 52:
		return (item->modifier & 3) + 2729LL;
	case 53:
		return 2733LL;
	case 54:
		return 2734LL;
	case 55:
		return (item->modifier & 3) + 2735LL;
	case 56:
		return (item->modifier % 5) + 2739LL;
	case 57:
		return 2744LL;
	case 58:
		return 2765LL;
	case 59:
		return 2766LL;
	case 60:
		return 2767LL;
	case 61:
		return 2768LL;
	case 62:
		return 2769LL;
	case 67:
		return (item->modifier % 3) + 2671LL;
	case 68:
		return (item->modifier % 3) + 2674LL;
	case 69:
		return (item->modifier % 3) + 2677LL;
	case 70:
		return (item->modifier % 3) + 2680LL;
	case 71:
		return (item->modifier & 1) + 2770LL;
	case 72:
		return 2772LL;
	case 73:
		return 2773LL;
	default:
		return 2636LL;
	}
}

uint64_t GetSpecialItemModel(cube::Item* item) {
	switch (item->id) {
	case 1:
		return 3489LL;
	case 2:
		return 3490LL;
	case 3:
		return 3492LL;
	case 4:
		return 2774LL;
	case 5:
		return 2775LL;
	case 6:
		return 2776LL;
	case 7:
		return 2777LL;
	case 8:
		return 2779LL;
	case 9:
		return 3202LL;
	case 10:
		return 2780LL;
	case 11:
		return 2781LL;
	case 12:
		return 3651LL;
	case 13:
		return 2745LL;
	case 14:
		return 2729LL;
	case 15:
		return 2730LL;
	case 16:
		return 2731LL;
	case 17:
		return 2732LL;
	case 18:
		return 3491LL;
	default:
		return 0LL;
	}
}

uint64_t GetEyePatchItemModel(cube::Item* item) {
	switch (item->id) {
	case 1:
		return 3578;
	case 2:
		return 3586;
	case 3:
		return 3587;
	case 4:
		return 3588;
	case 5:
		return 3591;
	case 6:
		return 3589;
	case 7:
		return 3590;
	default:
		return 3577;
	}
}

uint64_t GetLampItemModel(cube::Item* item) {
	return 3338LL;
}

uint64_t GetBuildingItemModel(cube::Item* item) {
	return 3139LL;
}

uint64_t GetPotionItemModel(cube::Item* item) {
	switch (item->id) {
	case 0:
		return 3639;
	case 1:
		return 3640;
	case 2:
		return 3641;
	case 3:
		return 3642;
	case 4:
		return 3272;
	case 5:
		return 3273;
	case 6:
		return 3274;
	default:
		return 2778;
	}
}

uint64_t GetGlyphItemModel(cube::Item* item) {
	return 3628LL;
}

uint64_t GetLootItemModel(cube::Item* item) {
	return 2772LL;
}

uint64_t GetManaSpiritItemModel(cube::Item* item) {
	return 3202LL;
}

uint64_t GetUnknownItemModel(cube::Item* item) {
	return 2778LL;
}

extern "C" cube::Sprite* cube__SpriteManager__GetItemModelSprite(cube::SpriteManager * sprite_manager, cube::Item * original_item)
{
	cube::Item item;
	((void(*)(cube::Item*, cube::Item*))CWOffset(0x1092B0))(original_item, &item); // copy item, but change things for item 0x16 quest items
	switch (item.category) {
	case cube::Item::CategoryType::Consumable : {
		uint64_t id = GetConsumableItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		return sprite_manager->sprites.at(id);
	}
	case cube::Item::CategoryType::Formula: {
		uint64_t id = GetScrollItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		return sprite_manager->sprites.at(id);
	}
	case cube::Item::CategoryType::Weapon: {
		uint64_t id = GetWeaponItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::ArmorChest: {
		uint64_t id = GetArmorChestItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::ArmorGloves: {
		uint64_t id = GetArmorGlovesItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::ArmorBoots: {
		uint64_t id = GetArmorBootsItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::ArmorShoulders: {
		uint64_t id = GetArmorShouldersItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Amulet: {
		uint64_t id = GetAmuletItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Ring: {
		uint64_t id = GetRingItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::UnknownVoxel: {
		uint64_t id = GetUnknownVoxelItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Collectible: {
		uint64_t id = GetCollectibleItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Coin: {
		uint64_t id = GetCoinItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::PlatinumCoin: {
		uint64_t id = GetPlatinumCoinItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::ManaCube: {
		uint64_t id = GetManaCubeItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Leftover: { // leftover
		uint64_t id = GetLeftoverItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Beak: {
		uint64_t id = GetBeakItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Painting: {
		uint64_t id = GetPaintingItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Vase: {
		uint64_t id = GetVaseItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Candle: {
		uint64_t id = GetCandleItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::PetCage: {
		uint64_t id = GetPetCageItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::PetFood: {
		uint64_t id = GetPetFoodItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Quest: {
		uint64_t id = GetQuestItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Artifact: {
		uint64_t id = ((uint64_t(*)(cube::SpriteManager*, int, int))CWOffset(0x1737B0))(sprite_manager, item.id, item.modifier);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Special: {
		uint64_t id = GetSpecialItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Lamp: {
		uint64_t id = GetLampItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::EyePatch: {
		uint64_t id = GetEyePatchItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Building: {
		uint64_t id = GetBuildingItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Potion: {
		uint64_t id = GetPotionItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Glyph: {
		uint64_t id = GetGlyphItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Loot: {
		uint64_t id = GetLootItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::ManaSpirit: {
		uint64_t id = GetManaSpiritItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	case cube::Item::CategoryType::Unknown: {
		uint64_t id = GetUnknownItemModel(&item);
		if (id < 0 || id >= sprite_manager->sprites.size()) {
			return nullptr;
		}
		else {
			return sprite_manager->sprites.at(id);
		}
	}
	default:
		return nullptr; //sprite_manager->sprites.at(3121LL);
	}
};

overwrite_function(0x173B10, cube__SpriteManager__GetItemModelSprite);