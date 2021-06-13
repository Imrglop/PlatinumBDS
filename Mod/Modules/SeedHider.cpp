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

#include "SeedHider.h"
#include "../../main.h"
#include <Windows.h>

void* getSeedRetAddy;

SeedHider::SeedHider() : Module(nid, name)
{
	this->nid = "seed-hider";
	this->name = "SeedHider";
}

SeedHider* globalThis;

// unsigned int __fastcall LevelData::getSeed(LevelData* this)
typedef uint(__fastcall* get_seed_t)(void* _this);
get_seed_t oGetSeed;

unsigned int LevelData_getSeedH(void* _this) {
	static unsigned int newSeed = (unsigned int)settings::getModuleInt(globalThis->nid, "new-seed");
	if (_ReturnAddress() == getSeedRetAddy) {
		return newSeed;
	}
	return 0;
}

bool SeedHider::enable() 
{
	using namespace main;
	globalThis = this;
	auto& funcs = getFunctions();
	void* getSeedF = reinterpret_cast<void*>(funcs.LevelData_getSeed);
	getSeedRetAddy;
	bool isLegacy = main::isLegacyVersion();
	if (!isLegacy) {
		llog("Hiding seed.");
		getSeedRetAddy = reinterpret_cast<void*>(funcs._getSeed_return_address);
		MH_CreateHook(getSeedF, LevelData_getSeedH, (LPVOID*)&oGetSeed);
		return true;
	}
	_PERR(this->name, "SeedHider does not support this BDS version.");
	return false;
}

void SeedHider::disable() 
{
}