cmake_minimum_required (VERSION 3.8)
project(project_CubeModLoader)
add_subdirectory(CWSDK)
add_library (CubeModLoader SHARED 
    crc.cpp
    DLL.cpp
    main.cpp
    mutex.cpp "macros.h" "callbacks/game/cube__Game__MouseUp.h" "callbacks/gui/cube__GUI__Load.h" "ModWidget.h" "ModWidget.cpp" "callbacks/world/cube__World__SpawnCreaturesMaybe.h" "callbacks/creature/cube__Creature__OnPlayerCombatDeath.h" "callbacks/gui/cube__ControlsWidget__ScrollUp.h" "callbacks/creature/cube__Creature__OnCreatureDeath.h" "callbacks/creature/cube__Creature__OnPlayerDrownDeath.h" "callbacks/creature/cube__Creature__OnPlayerFallDeath.h"  "callbacks/game/cube__Game__Update.h" "callbacks/item/cube__Item__OnGetSellingPrice.h" "callbacks/creature/cube__Creature__CanEquipItem.h" "callbacks/item/cube__Item__OnGetGoldBagValue.h" "callbacks/game/cube__Game__HandleMouseWheel.h" "callbacks/SpriteManagerLoadSpriteHandler.h" "callbacks/item/cube__Item__OnGetItemNameColor.h"  "callbacks/item/cube__Item__OnGetConsumableUseTime.h" "callbacks/creature/cube__Creature__GetNextAbilityId.h" "callbacks/game/cube__Game__CraftingInventoryUpdate.h" "callbacks/gui/cube__CharacterPreviewWidget__Draw.h" "callbacks/gui/cube__ControlsWidget__ScrollDown.h" "callbacks/gui/cube__ControlsWidget__UpdateScrollBarPosition.h" "callbacks/gui/cube__ControlsWidget__ScrollGrab.h")
target_link_libraries (CubeModLoader LINK_PUBLIC CWSDK)