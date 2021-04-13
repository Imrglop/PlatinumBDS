/*
*
* ------------------------------\
*          Platinum             |
*  Bedrock Dedicated Server     |
*  mod for enhancements and     |
*  more customization.          |
* ------------------------------/
*
* This is Free Software: You can edit and distribute it
* under the MIT license.
* author: PlatinumBDS's contributors
* link: https://github.com/Imrglop/PlatinumBDS
*/

#pragma once
#include "shared.h"

struct ModuleData {
	uintptr_t base;
	uintptr_t functionEnd;
};

struct ModuleFunctions {
#define INIT(x) uintptr_t x = 0;
	INIT(KnockbackRules_useLegacyKnockback)
	INIT(Mob_knockback)
	INIT(Mob_hurtEffects_setHurtTime)
	//INIT(ItemUseInventoryTransaction_handle)
	INIT(MovePlayerPacket__read)
	INIT(LevelSettings_LevelSettings_setSeed)
#undef INIT
};

namespace main
{
	ModuleData& getData();
	ModuleFunctions& getFunctions();
};