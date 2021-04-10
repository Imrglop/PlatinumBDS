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
	uintptr_t KnockbackRules_useLegacyKnockback = 0;
	uintptr_t Mob_knockback = 0;
	uintptr_t Mob_hurtEffects_setHurtTime = 0;
	uintptr_t ItemUseInventoryTransaction_handle = 0;
};

namespace main
{
	ModuleData& getData();
	ModuleFunctions& getFunctions();
};