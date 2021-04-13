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

SeedHider::SeedHider() : Module(nid, name)
{
	this->nid = "seed-hider";
	this->name = "SeedHider";
}

bool SeedHider::enable() 
{
	using namespace main;
	auto& funcs = getFunctions();
	void* lpSetSeed = reinterpret_cast<void*>(funcs.LevelSettings_LevelSettings_setSeed);
	if (lpSetSeed != nullptr) {
		size_t size = 3;

		DWORD dwOldProtect;

		VirtualProtect(lpSetSeed, size, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		memset(lpSetSeed, 0x90, size);
		VirtualProtect(lpSetSeed, size, dwOldProtect, &dwOldProtect);
		nlog("Seed hidden.");
		return true;
	}
	_PERR(this->name, "SeedHider does not support this BDS version.");
	return false;
}

void SeedHider::disable() 
{
}