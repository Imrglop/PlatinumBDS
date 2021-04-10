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

#include "HurtTime.h"
#include "../../main.h"
#include "../../Settings/settings.h"

HurtTime::HurtTime() : Module(nid, name)
{
	this->nid = "hurt-time";
	this->name = "HurtTime";
}

bool HurtTime::enable()
{
	using namespace settings;
	auto& funcs = main::getFunctions();
	int hurtTime = getModuleInt(this->nid, "hurt-time");

	byte* lpOpcode = reinterpret_cast<byte*>(funcs.Mob_hurtEffects_setHurtTime);
	if (lpOpcode == nullptr) {
		lerr("Set hurt time is a null pointer!");
		return false;
	}

	int instructionOffset = 6;
	int* lpHurtTime = reinterpret_cast<int*>(lpOpcode + instructionOffset);

	DWORD oldProtect;
	VirtualProtect(lpHurtTime, sizeof(int), PAGE_EXECUTE_READWRITE, &oldProtect);
	*lpHurtTime = hurtTime;
	VirtualProtect(lpHurtTime, sizeof(int), oldProtect, &oldProtect);
	return true;
}

void HurtTime::disable()
{
}