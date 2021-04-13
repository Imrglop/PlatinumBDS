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
#include "BasicAntiCheat.h"
#include "../../Settings/settings.h"
#include "../../main.h"

BasicAntiCheat::BasicAntiCheat() : Module(nid, name)
{
	this->nid = "anti-cheat";
	this->name = "BasicAntiCheat";
}

MovePlayerPacketRead readMovePlayerPacket = NULL;

StreamReadResult movePlayerPacketReadHook(ReadOnlyBinaryStream* lpPacket) {
	//Vec3* lpPos = &lpMovePacket->position;
	//llog("pos: " << lpPos/*<< lpPos.x << ", " << lpPos.y << ", " << lpPos.z*/);
	return readMovePlayerPacket(lpPacket);
}

bool BasicAntiCheat::enable() {
	using namespace settings;
	using namespace main;
	_PWARN(this->name, "This module is experimental.");
	isAntiCrasher = getModuleBool(this->nid, "anti-crasher");
	auto& funcs = getFunctions();
	if (isAntiCrasher) {
		_PWARN(this->name, "Anti Crasher is coming soon.");
		auto status = MH_CreateHook(reinterpret_cast<LPVOID>(funcs.MovePlayerPacket__read), movePlayerPacketReadHook,
			reinterpret_cast<LPVOID*>(&readMovePlayerPacket));
		if (status != MH_OK) {
			_PERR(this->name, "Could not enable anti crasher!\n MH_STATUS = " << status << "\n Function: " << reinterpret_cast<LPVOID>(funcs.MovePlayerPacket__read));
			return false;
		}
	}
	return true;
}

void BasicAntiCheat::disable() {
}