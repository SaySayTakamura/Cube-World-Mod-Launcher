#pragma once
#include "../../CWSDK/cwsdk.h"
#include <cube/Item.h>
extern "C" void cube__Game__CraftingInventoryUpdate(cube::Game * game)
{
    //cube::Item water_flask(cube::Item::Collectible, 26);
    //cube::Item heart_flower(cube::Item::Collectible, 22);
    //game->world->local_creature->DropItem(&water_flask);
    //game->world->local_creature->DropItem(&heart_flower);

	cube::InventoryWidget* widget = game->gui.crafting_inventory_widget;
	auto itemVector = widget->itemVector;
	if (itemVector != nullptr)
	{
        if (itemVector->size() == 0) {
            itemVector->clear();
            std::vector<cube::ItemStack> weapon_vec;
            std::vector<cube::ItemStack> armor_vec;
            std::vector<cube::ItemStack> amulet_vec;
            std::vector<cube::ItemStack> cooking_vec;
            std::vector<cube::ItemStack> alchemy_vec;
            std::vector<cube::ItemStack> ingredient_vec;

            itemVector->push_back(weapon_vec);
            itemVector->push_back(armor_vec);
            itemVector->push_back(amulet_vec);
            itemVector->push_back(cooking_vec);
            itemVector->push_back(alchemy_vec);
            itemVector->push_back(ingredient_vec);
        }

        std::vector<cube::ItemStack>* weapon_vec = &itemVector->at(0);
        std::vector<cube::ItemStack>* armor_vec = &itemVector->at(1);
        std::vector<cube::ItemStack>* amulet_vec = &itemVector->at(2);
        std::vector<cube::ItemStack>* cooking_vec = &itemVector->at(3);
        std::vector<cube::ItemStack>* alchemy_vec = &itemVector->at(4);
        std::vector<cube::ItemStack>* ingredient_vec = &itemVector->at(5);
        weapon_vec->clear();
        armor_vec->clear();
        amulet_vec->clear();
        cooking_vec->clear();
        alchemy_vec->clear();
        ingredient_vec->clear();

        cube::Creature* creature = game->world->local_creature;

        // Original algorithm used for the seed.
        int v7 = ((57 * creature->entity_data.current_region.y + 62969 + creature->entity_data.current_region.x) << 13) ^ (57 * creature->entity_data.current_region.y + 62969 + creature->entity_data.current_region.x);
        srand(100000 - ((v7 * (60493 * v7 * v7 + 19990303) - 771171059) & 0x7FFFFFFFu) / 0x53E2);

        for (int rarity = 0; rarity < 4; rarity++) {
            // search for the book
            if (rarity == 1) continue;
            if (rarity > 0) {
                auto special_tab = creature->inventory_tabs.at(1);
                bool found = false;
                for (cube::ItemStack stack : special_tab) {
                    cube::Item item = stack.item;
                    if (item.region == creature->entity_data.current_region) {
                        if (item.category == cube::Item::Special) {
                            if (item.id - 13 == rarity || item.id == 14) {
                                found = true;
                            }
                        }
                    }
                }
                if (!found)
                    continue;
            }
            
            // Original algorithm used for the seed.
            int seed = ((57 * creature->entity_data.current_region.y + 62969 + creature->entity_data.current_region.x) << 13) ^ (57 * creature->entity_data.current_region.y + 62969 + creature->entity_data.current_region.x);
            srand(rarity - ((seed * (60493 * seed * seed + 19990303) - 771171059) & 0x7FFFFFFFu) / 0x53E2 + 100000);

            // Weapons
            switch (creature->entity_data.classType) {
            case cube::Creature::ClassType::Warrior: {
                cube::Item onehanded_item(cube::Item::Weapon, rand() % 3);
                cube::Item shield_item(cube::Item::Weapon, 13);
                cube::Item twohanded_item(cube::Item::Weapon, 15 + rand() % 3);
                onehanded_item.material = cube::Item::Iron;
                onehanded_item.modifier = rand();
                onehanded_item.rarity = rarity;
                onehanded_item.region = creature->entity_data.current_region;

                shield_item.material = cube::Item::Iron;
                shield_item.modifier = rand();
                shield_item.rarity = rarity;
                shield_item.region = creature->entity_data.current_region;

                twohanded_item.material = cube::Item::Iron;
                twohanded_item.modifier = rand();
                twohanded_item.rarity = rarity;
                twohanded_item.region = creature->entity_data.current_region;

                weapon_vec->push_back(cube::ItemStack(0, onehanded_item));
                weapon_vec->push_back(cube::ItemStack(0, shield_item));
                weapon_vec->push_back(cube::ItemStack(0, twohanded_item));
                break;
            }
            case cube::Creature::ClassType::Ranger: {
                cube::Item bow_item(cube::Item::Weapon, 6);
                cube::Item crossbow_item(cube::Item::Weapon, 7);
                cube::Item boomerang_item(cube::Item::Weapon, 8);
                bow_item.material = cube::Item::Wood;
                bow_item.modifier = rand();
                bow_item.rarity = rarity;
                bow_item.region = creature->entity_data.current_region;

                crossbow_item.material = cube::Item::Wood;
                crossbow_item.modifier = rand();
                crossbow_item.rarity = rarity;
                crossbow_item.region = creature->entity_data.current_region;

                boomerang_item.material = cube::Item::Wood;
                boomerang_item.modifier = rand();
                boomerang_item.rarity = rarity;
                boomerang_item.region = creature->entity_data.current_region;

                weapon_vec->push_back(cube::ItemStack(0, bow_item));
                weapon_vec->push_back(cube::ItemStack(0, crossbow_item));
                weapon_vec->push_back(cube::ItemStack(0, boomerang_item));
                break;
            }
            case cube::Creature::ClassType::Mage: {
                cube::Item wand_item(cube::Item::Weapon, 11);
                cube::Item staff_item(cube::Item::Weapon, 10);
                cube::Item bracelet_item(cube::Item::Weapon, 12);
                wand_item.material = cube::Item::Wood;
                wand_item.modifier = rand();
                wand_item.rarity = rarity;
                wand_item.region = creature->entity_data.current_region;

                staff_item.material = cube::Item::Wood;
                staff_item.modifier = rand();
                staff_item.rarity = rarity;
                staff_item.region = creature->entity_data.current_region;

                bracelet_item.material = cube::Item::Gold + rand() % 2; // gold or silver.
                bracelet_item.modifier = rand();
                bracelet_item.rarity = rarity;
                bracelet_item.region = creature->entity_data.current_region;

                weapon_vec->push_back(cube::ItemStack(0, wand_item));
                weapon_vec->push_back(cube::ItemStack(0, staff_item));
                weapon_vec->push_back(cube::ItemStack(0, bracelet_item));
                break;
            }
            case cube::Creature::ClassType::Rogue: {
                cube::Item dagger_item(cube::Item::Weapon, 3);
                cube::Item fist_item(cube::Item::Weapon, 4);
                cube::Item longsword_item(cube::Item::Weapon, 5);
                dagger_item.material = cube::Item::Iron;
                dagger_item.modifier = rand();
                dagger_item.rarity = rarity;
                dagger_item.region = creature->entity_data.current_region;

                fist_item.material = cube::Item::Iron;
                fist_item.modifier = rand();
                fist_item.rarity = rarity;
                fist_item.region = creature->entity_data.current_region;

                longsword_item.material = cube::Item::Iron;
                longsword_item.modifier = rand();
                longsword_item.rarity = rarity;
                longsword_item.region = creature->entity_data.current_region;

                weapon_vec->push_back(cube::ItemStack(0, dagger_item));
                weapon_vec->push_back(cube::ItemStack(0, fist_item));
                weapon_vec->push_back(cube::ItemStack(0, longsword_item));
                break;
            }
            }

            // Armors
            cube::Item chest_item(cube::Item::ArmorChest, 0);
            cube::Item shoulders_item(cube::Item::ArmorShoulders, 0);
            cube::Item gloves_item(cube::Item::ArmorGloves, 0);
            cube::Item boots_item(cube::Item::ArmorBoots, 0);
            switch (creature->entity_data.classType)
            {
            case 1u:
                chest_item.material = cube::Item::Iron;
                shoulders_item.material = cube::Item::Iron;
                gloves_item.material = cube::Item::Iron;
                boots_item.material = cube::Item::Iron;
                break;
            case 2u:
                chest_item.material = cube::Item::Linnen;
                shoulders_item.material = cube::Item::Linnen;
                gloves_item.material = cube::Item::Linnen;
                boots_item.material = cube::Item::Linnen;
                break;
            case 3u:
                chest_item.material = cube::Item::Silk;
                shoulders_item.material = cube::Item::Silk;
                gloves_item.material = cube::Item::Silk;
                boots_item.material = cube::Item::Silk;
                break;
            case 4u:
                chest_item.material = cube::Item::Cotton;
                shoulders_item.material = cube::Item::Cotton;
                gloves_item.material = cube::Item::Cotton;
                boots_item.material = cube::Item::Cotton;
                break;
            }
            chest_item.modifier = rand();
            shoulders_item.modifier = rand();
            gloves_item.modifier = rand();
            boots_item.modifier = rand();

            chest_item.rarity = rarity;
            shoulders_item.rarity = rarity;
            gloves_item.rarity = rarity;
            boots_item.rarity = rarity;

            chest_item.region = creature->entity_data.current_region;
            shoulders_item.region = creature->entity_data.current_region;
            gloves_item.region = creature->entity_data.current_region;
            boots_item.region = creature->entity_data.current_region;

            armor_vec->push_back(cube::ItemStack(0, chest_item));
            armor_vec->push_back(cube::ItemStack(0, shoulders_item));
            armor_vec->push_back(cube::ItemStack(0, gloves_item));
            armor_vec->push_back(cube::ItemStack(0, boots_item));


            // Amulets
            cube::Item amulet_item(cube::Item::Amulet, 0);
            cube::Item ring_item(cube::Item::Ring, 0);

            amulet_item.material = cube::Item::Gold + rand() % 2; // gold or silver.
            amulet_item.region = creature->entity_data.current_region;
            amulet_item.modifier = rand();
            amulet_item.rarity = rarity;
            ring_item.material = cube::Item::Gold + rand() % 2;
            ring_item.region = creature->entity_data.current_region;
            ring_item.modifier = rand();
            ring_item.rarity = rarity;

            amulet_vec->push_back(cube::ItemStack(0, amulet_item));
            amulet_vec->push_back(cube::ItemStack(0, ring_item));
        }

        // Cooking
        // TODO: get possible craft amount.
        cube::Item ginseng_soup_item(cube::Item::Consumable, 4);
        cube::Item pineaple_slice_item(cube::Item::Consumable, 10);
        cube::Item mushroom_spit_item(cube::Item::Consumable, 8);
        cube::Item pumpkin_muffin_item(cube::Item::Consumable, 11);
        cube::Item snowberry_mash_item(cube::Item::Consumable, 7);
        cube::Item lemonade_item(cube::Item::Potion, 4);
        cube::Item hot_chocolate_item(cube::Item::Potion, 5);
        cube::Item green_smoothie_item(cube::Item::Potion, 6);

        cooking_vec->push_back(cube::ItemStack(0, ginseng_soup_item));
        cooking_vec->push_back(cube::ItemStack(0, pineaple_slice_item));
        cooking_vec->push_back(cube::ItemStack(0, mushroom_spit_item));
        cooking_vec->push_back(cube::ItemStack(0, pumpkin_muffin_item));
        cooking_vec->push_back(cube::ItemStack(0, snowberry_mash_item));
        cooking_vec->push_back(cube::ItemStack(0, lemonade_item));
        cooking_vec->push_back(cube::ItemStack(0, hot_chocolate_item));
        cooking_vec->push_back(cube::ItemStack(0, green_smoothie_item));

        // Alchemy
        // TODO: get possible craft amount.
        cube::Item life_potion_item(cube::Item::Consumable, 1);
        cube::Item cactus_potion_item(cube::Item::Consumable, 2);
        cube::Item life_elixir_item(cube::Item::Potion, 0);
        cube::Item power_elixir_item(cube::Item::Potion, 1);
        cube::Item toughness_elixir_item(cube::Item::Potion, 2);
        cube::Item sanity_elixir_item(cube::Item::Potion, 3);

        alchemy_vec->push_back(cube::ItemStack(0, life_potion_item)); // GetCraftableQuantity(game, &life_potion_item)
        alchemy_vec->push_back(cube::ItemStack(0, cactus_potion_item));
        alchemy_vec->push_back(cube::ItemStack(0, life_elixir_item));
        alchemy_vec->push_back(cube::ItemStack(0, power_elixir_item));
        alchemy_vec->push_back(cube::ItemStack(0, toughness_elixir_item));
        alchemy_vec->push_back(cube::ItemStack(0, sanity_elixir_item));

        // Ingredients
        // TODO: get possible craft amount.
        cube::Item water_flask_item(cube::Item::Collectible, 26);
        cube::Item heart_flower_item(cube::Item::Collectible, 22);
        cube::Item iron_cube_item(cube::Item::Collectible, 10);
        cube::Item wood_cube_item(cube::Item::Collectible, 10);
        cube::Item gold_cube_item(cube::Item::Collectible, 10);
        cube::Item silver_cube_item(cube::Item::Collectible, 10);

        iron_cube_item.material = cube::Item::Iron;
        wood_cube_item.material = cube::Item::Wood;
        gold_cube_item.material = cube::Item::Gold;
        silver_cube_item.material = cube::Item::Silver;

        ingredient_vec->push_back(cube::ItemStack(0, water_flask_item));
        ingredient_vec->push_back(cube::ItemStack(0, heart_flower_item));
        ingredient_vec->push_back(cube::ItemStack(0, iron_cube_item));
        ingredient_vec->push_back(cube::ItemStack(0, wood_cube_item));
        ingredient_vec->push_back(cube::ItemStack(0, gold_cube_item));
        ingredient_vec->push_back(cube::ItemStack(0, silver_cube_item));

        // set possible craft amount TODO: make it work
        /*B2EE0(game, 0, weapon_vec);
        B2EE0(game, 1, armor_vec);
        B2EE0(game, 2, amulet_vec);
        B2EE0(game, 3, cooking_vec);
        B2EE0(game, 4, alchemy_vec);
        B2EE0(game, 5, ingredient_vec);*/
	}
}

overwrite_function(0xB2180, cube__Game__CraftingInventoryUpdate); 
