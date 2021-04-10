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

#include "Knockback.h"
#include "../../main.h"
#include "../../Settings/settings.h"

Mob_knockback mobKnockback = NULL;

Knockback::Knockback() : Module(nid, name) {
	this->nid = "knockback";
	this->name = "Knockback";
}

bool legacyKnockbackHook(void* _KnockbackRules) {
	return true;
}

Knockback* globalThis = NULL;

void __cdecl mobKnockbackHook(void* _this, void* targetActor, float f1, float f2, float f3, float horizontalKnockback, float verticalKnockback)
{
	bool isEditingKnockback = settings::getModuleBool(globalThis->nid, "is-editing-knockback");
	if (isEditingKnockback) {
		bool isOffset = settings::getModuleBool(globalThis->nid, "is-offset");
		float yKb = settings::getModuleFloat(globalThis->nid, "vertical-knockback");
		float xzKb = settings::getModuleFloat(globalThis->nid, "horizontal-knockback");
		if (isOffset) {
			horizontalKnockback += xzKb;
			verticalKnockback += yKb;
		}
		else {
			horizontalKnockback = xzKb;
			verticalKnockback = yKb;
		}
	}
	mobKnockback(_this, targetActor, f1, f2, f3, horizontalKnockback, verticalKnockback);
}

bool Knockback::enable() {
	nlog("Setting up knockback hooks.");
	globalThis = this;
	auto& funcs = main::getFunctions();
	isLegacyKb = settings::getModuleBool(nid, "use-legacy-knockback");
	if (isLegacyKb) {
		auto status = MH_CreateHook(reinterpret_cast<LPVOID>(funcs.KnockbackRules_useLegacyKnockback), 
			legacyKnockbackHook, NULL);
		if (status != MH_OK) {
			lerr("LegacyKnockbackHook doesn't work! MH_STATUS = " << status);
			return false;
		}
	}
	auto status = MH_CreateHook(reinterpret_cast<LPVOID>(funcs.Mob_knockback), mobKnockbackHook,
		reinterpret_cast<LPVOID*>(&mobKnockback));
	if (status != MH_OK) {
		lerr("Mob::knockback hook doesn't work! MH_STATUS = " << status);
		lerr("Mob knockback fn: " << reinterpret_cast<LPVOID>(funcs.Mob_knockback));
		return false;
	}
	return true;
}

void Knockback::disable()
{
	if (isLegacyKb) {
		MH_DisableHook((void*)main::getFunctions().KnockbackRules_useLegacyKnockback);
	}
	MH_DisableHook((void*)main::getFunctions().Mob_knockback);
}
