#pragma once
#include "../../CWSDK/cwsdk.h"
#include <cube/Item.h>

enum CraftRequirementType : int {
    None = 0,
    Water = 1,
    Furnace = 3,
    Anvil = 4,
    SpinningWheel = 5,
    Loom = 6,
    Saw = 7,
    Workbench = 8,
    Campfire = 9
};

class ReversedItemStack {
public:
    cube::Item item;
    int amount;

    ReversedItemStack() {};
    ReversedItemStack(int quantity, cube::Item item) {
        this->amount = quantity;
        this->item = item;
    };
};

class CraftItem : public cube::Item {
public:
    CraftRequirementType type;
    std::vector<ReversedItemStack> craft_vec;
};

void AddSpecialCubes(cube::Item* preview_item, CraftItem* dest_item) {
    cube::Item::CategoryType category = (cube::Item::CategoryType)preview_item->category;
    int id = preview_item->id;

    if (dest_item->rarity < 1 || dest_item->rarity > 4) return;
    cube::Item special_cube(cube::Item::Collectible, 11); // Special Cube
    int amount = 2;
    if (category == cube::Item::ArmorChest) amount = 4;
    if (category == cube::Item::Weapon && id <= 23)
    {
        switch (id) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 15:
        case 16:
        case 17:
        case 18:
            amount = 4;
            break;
        }
    }
    special_cube.id = 32 + (dest_item->rarity-1);
    special_cube.rarity = dest_item->rarity;
    dest_item->craft_vec.push_back(ReversedItemStack(amount, special_cube));
}

extern "C" bool cube__Game__LoadItemCraft(cube::World * world, cube::Item * preview_item, CraftItem * dest_item)
{
    cube::Item empty_item;
    dest_item->Copy(&empty_item);
    dest_item->type = None;

    std::vector<ReversedItemStack> vector = {};

    dest_item->craft_vec = vector;

    if (preview_item->category == cube::Item::CategoryType::Glyph) {
        // Nothing?
        return 1;
    }
    dest_item->Copy(preview_item);
    switch (preview_item->category) {

    case cube::Item::Consumable: {
        switch (preview_item->id) {
        case 1: { // Life Potion
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 22))); // Heart flower
            switch (preview_item->rarity) {
            case 1:
                dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 28, 1))); // Special rarity item
                break;
            case 2:
                dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 29, 2))); // Special rarity item
                break;
            case 3:
                dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 30, 3))); // Special rarity item
                break;
            case 4:
                dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 25, 4))); // Special rarity item
                break;
            default:
                break;
            }
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water bottle
            break;
        }
        case 2: { // Cactus Potion
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 23))); // Cactus
            cube::Item glass_bottle(cube::Item::Collectible, 12);
            glass_bottle.material = cube::Item::Glass;
            dest_item->craft_vec.push_back(ReversedItemStack(1, glass_bottle)); // Glass Bottle
            break;
        }
        case 3: { // Essence of Wisdom
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 29, 1))); // Manaorchid
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water bottle
            break;
        }
        case 4: { // Ginseng Soup
            dest_item->craft_vec.push_back(ReversedItemStack(4, cube::Item(cube::Item::Collectible, 20))); // Ginseng root
            dest_item->type = Campfire;
            break;
        }
        case 7: { // Snowberry Mash
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 27))); // Snowberry
            break;
        }
        case 8: { // Mushroom Spit
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 15))); // Mushroom
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 21))); // Onion slice
            dest_item->type = Campfire;
            break;
        }
        case 10: { // Pineaple Splice
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 17))); // Pineaple
            break;
        }
        case 11: { // Pumpkin Muffin
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 16))); // Pumpkin
            dest_item->type = Campfire;
            break;
        }
        case 12: { // Greater Life Potion
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 22))); // Heart flower
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 25, 1))); // Soulflower
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water bottle
            break;
        }
        default: {
            break;
        }
        }
        return 1;
    }

    case cube::Item::Weapon: {
     // TODO: do this pls
        cube::Item cube(cube::Item::Collectible, 10); // cube
        cube.material = cube::Item::Iron;
        cube::Item special_cube(cube::Item::Collectible, 10); // cube
        switch (preview_item->id)
        {
        case 0: // Sword
        case 1: // Axe
        case 2: // Mace
        case 3: // Dagger
        case 0xD: { // Shield
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), cube));
            dest_item->type = Anvil;
            break;
        }
        case 4: { // Fist
            dest_item->craft_vec.push_back(ReversedItemStack((4 * preview_item->rarity) + 4, cube));
            cube::Item cotton_yard(cube::Item::Collectible, 9);
            cotton_yard.material = cube::Item::Cotton;
            dest_item->craft_vec.push_back(ReversedItemStack((2 * preview_item->rarity) + 2, cotton_yard)); // Cotton yard
            dest_item->type = Anvil;
            break;
        }
        case 5: // Longsword
        case 0xF: // Greatsword
        case 0x10: // Greataxe
        case 0x11: { // Greatmace
            dest_item->craft_vec.push_back(ReversedItemStack(10 * (preview_item->rarity + 1), cube));
            dest_item->type = Anvil;
            break;
        }
        case 6: { // Bow
            cube.material = cube::Item::Wood;
            dest_item->craft_vec.push_back(ReversedItemStack(10 * (preview_item->rarity + 1), cube));
            cube::Item linnen_yard(cube::Item::Collectible, 9);
            linnen_yard.material = cube::Item::Linnen;
            dest_item->craft_vec.push_back(ReversedItemStack(preview_item->rarity + 1, linnen_yard)); // Linnen yard
            dest_item->type = Workbench;
            break;
        }
        case 7: { // Crossbow
            dest_item->craft_vec.push_back(ReversedItemStack((2 * preview_item->rarity) + 2, cube));
            cube.material = cube::Item::Wood;
            dest_item->craft_vec.push_back(ReversedItemStack(8 * preview_item->rarity + 8, cube));
            cube::Item linnen_yard(cube::Item::Collectible, 9);
            linnen_yard.material = cube::Item::Linnen;
            dest_item->craft_vec.push_back(ReversedItemStack(preview_item->rarity + 1, linnen_yard)); // Linnen yard
            dest_item->type = Workbench;
            break;
        }
        case 8: // Boomerang    
        case 0xA: // Staff
        case 0xB: { // Wand
            cube.material = cube::Item::Wood;
            dest_item->craft_vec.push_back(ReversedItemStack(10 * (preview_item->rarity + 1), cube));
            dest_item->type = Workbench;
            break;
        }
        case 0xC: { // Bracelet
            cube.material = preview_item->material;
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), cube));
            dest_item->type = Anvil;
            break;
        }
        default: 
            break;
        }
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::ArmorChest: {
        cube::Item material(cube::Item::Collectible, 10); // cube
        material.material = preview_item->material;
        if (material.material == cube::Item::MaterialType::Iron)
        {
            dest_item->craft_vec.push_back(ReversedItemStack(2 * (5 * (preview_item->rarity + 1)), material));
            dest_item->type = Anvil;
        }
        else
        {
            material.id = 9; // yarn
            dest_item->craft_vec.push_back(ReversedItemStack(2 * (5 * (preview_item->rarity + 1)), material));
            dest_item->type = Loom;
        }
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::ArmorGloves: {
        cube::Item material(cube::Item::Collectible, 10); // cube
        material.material = preview_item->material;
        if (material.material == cube::Item::MaterialType::Iron)
        {
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), material));
            dest_item->type = Anvil;
        }
        else
        {
            material.id = 9; // yarn
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), material));
            dest_item->type = Loom;
        }
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::ArmorBoots: {
        cube::Item material(cube::Item::Collectible, 10); // cube
        material.material = preview_item->material;
        if (material.material == cube::Item::MaterialType::Iron)
        {
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), material));
            dest_item->type = Anvil;
        }
        else
        {
            material.id = 9; // yarn
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), material));
            dest_item->type = Loom;
        }
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::ArmorShoulders: {
        cube::Item material(cube::Item::Collectible, 10); // cube
        material.material = preview_item->material;
        if (material.material == cube::Item::MaterialType::Iron)
        {
            dest_item->craft_vec.push_back(ReversedItemStack(6 * (preview_item->rarity + 1), material));
            dest_item->type = Anvil;
        }
        else
        {
            material.id = 9; // yarn
            dest_item->craft_vec.push_back(ReversedItemStack(6 * (preview_item->rarity + 1), material));
            dest_item->type = Loom;
        }
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::Amulet:
    case cube::Item::Ring: {
        cube::Item material(cube::Item::Collectible, 10); // cube
        material.material = preview_item->material;
        dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), material));
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::Collectible: {
        switch (preview_item->id) {
        case 9: { // Yarn
            cube::Item material(cube::Item::Collectible, 10); // cube
            switch (preview_item->material) {
            case cube::Item::Silk: {
                material.id = 6; // Cobweb
                material.material = 0;
                break;
            }
            case cube::Item::Linnen: {
                material.id = 5; // Fiber
                material.material = cube::Item::Plant;
                break;
            }
            case cube::Item::Cotton: {
                material.id = 11; // Capsule
                material.material = cube::Item::Cotton;
                break;
            }
            default:
                break;
            }
            dest_item->craft_vec.push_back(ReversedItemStack(1, material));
            dest_item->type = SpinningWheel;
            break;
        }

        case 10: { // Cube
            cube::Item nugget(cube::Item::Collectible, 0); // Nugget
            dest_item->type = Furnace;
            nugget.material = preview_item->material;
            if (nugget.material == cube::Item::Wood) {
                nugget.id = 1; // Log
                dest_item->type = Saw;
            }
            dest_item->craft_vec.push_back(ReversedItemStack(1, nugget));
            break;
        }

        case 22: { // HeartFlower
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 24))); // IceFlower
            dest_item->type = Campfire;
            break;
        }

        case 26: { // Water Flask
            cube::Item glass_bottle(cube::Item::Collectible, 12); // Glass bottle
            glass_bottle.material = cube::Item::Glass;
            dest_item->craft_vec.push_back(ReversedItemStack(1, glass_bottle));
            dest_item->type = Water;
            break;
        }

        }
        AddSpecialCubes(preview_item, dest_item);
        break;
    }

    case cube::Item::Potion: {
        switch (preview_item->id) {
        case 0: { // Elixir of life
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), cube::Item(cube::Item::Collectible, 22))); // HeartFlower
            dest_item->craft_vec.push_back(ReversedItemStack(preview_item->rarity + 1, cube::Item(cube::Item::Collectible, 20))); // Ginseng root
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            break;
        }
        case 1: { // Elixir of power
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), cube::Item(cube::Item::Collectible, 15))); // Mushroom
            dest_item->craft_vec.push_back(ReversedItemStack(2 * (preview_item->rarity + 2), cube::Item(cube::Item::Collectible, 36))); // Dragon root
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            break;
        }
        case 2: { // Elixir of toughness
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), cube::Item(cube::Item::Collectible, 15))); // Mushroom
            dest_item->craft_vec.push_back(ReversedItemStack(2 * (preview_item->rarity + 2), cube::Item(cube::Item::Collectible, 37))); // Dew drop
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            break;
        }
        case 3: { // Elixir of sanity
            dest_item->craft_vec.push_back(ReversedItemStack(5 * (preview_item->rarity + 1), cube::Item(cube::Item::Collectible, 19))); // Shimmer Mushroom
            dest_item->craft_vec.push_back(ReversedItemStack(2 * (preview_item->rarity + 2), cube::Item(cube::Item::Collectible, 29))); // Manaorchid
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            break;
        }
        case 4: { // Lemonade
            dest_item->craft_vec.push_back(ReversedItemStack(2, cube::Item(cube::Item::Collectible, 38))); // Sugar Cube
            dest_item->craft_vec.push_back(ReversedItemStack(2, cube::Item(cube::Item::Collectible, 39))); // Ice Cube
            dest_item->craft_vec.push_back(ReversedItemStack(3, cube::Item(cube::Item::Collectible, 40))); // Lemon
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            break;
        }
        case 5: { // Hot Chocolate
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 38))); // Sugar Cube
            dest_item->craft_vec.push_back(ReversedItemStack(3, cube::Item(cube::Item::Collectible, 43))); // Cocoa bean
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            dest_item->type = Campfire;
            break;
        }
        case 6: { // Green Smoothie
            dest_item->craft_vec.push_back(ReversedItemStack(2, cube::Item(cube::Item::Collectible, 41))); // Banana
            dest_item->craft_vec.push_back(ReversedItemStack(2, cube::Item(cube::Item::Collectible, 42))); // Kale
            dest_item->craft_vec.push_back(ReversedItemStack(1, cube::Item(cube::Item::Collectible, 26))); // Water flask
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        AddSpecialCubes(preview_item, dest_item);
    }
    return 1;
}

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

        for (int rarity = 0; rarity < 5; rarity++) {
            // search for the book
            if (rarity > 0) {
                auto special_tab = creature->inventory_tabs.at(1);
                bool found = false;
                for (cube::ItemStack stack : special_tab) {
                    cube::Item item = stack.item;
                    if (item.region == creature->entity_data.current_region) {
                        if (item.category == cube::Item::Special) {
                            if (item.id - 13 >= rarity && item.id < 18) {
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

        // REMOVE THESE (A craft is define but not added to the craft list)
        /*cube::Item wisdom_item(cube::Item::Consumable, 3);
        cube::Item greater_life_potion_item(cube::Item::Consumable, 12);
        alchemy_vec->push_back(cube::ItemStack(0, wisdom_item));
        alchemy_vec->push_back(cube::ItemStack(0, greater_life_potion_item));*/

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
overwrite_function(0x2AEC30, cube__Game__LoadItemCraft);
