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
#include "../../main.h"
#include "../../Sig/vtable_hook.h"
#include "../../Settings/settings.h"

typedef StreamReadResult(__fastcall* moveplayerpacket_read_t)(MovePlayerPacket*, __int64);

moveplayerpacket_read_t oMovePlayerRead;

static const float maxTp = 3e7F + 1;

StreamReadResult BasicAntiCheat::MovePlayerPacket_readHook(MovePlayerPacket* _this, __int64 binaryStream)
{
	auto res = oMovePlayerRead(_this, binaryStream);
	if (_this->position.x > maxTp ||
		_this->position.y > maxTp ||
		_this->position.z > maxTp) { // crasher packet
		_this->position.x = 0;
		_this->position.y = 0;
		_this->position.z = 0;
	}
	return res;
}

BasicAntiCheat::BasicAntiCheat() : Module(nid, name)
{
	this->nid = "anti-cheat";
	this->name = "BasicAntiCheat";
}

set_pos_t setActorPos;
base_tick_t baseTick;
get_descriptor_t getItemDescriptor;

void __cdecl handleSpawnXPHook(void* _this, NetworkIdentifier* const& ni, void* const& _SpawnExperienceOrb_packet)
{
}



bool BasicAntiCheat::enable() 
{
	using namespace settings;
	using namespace main;
	isAntiXP = getModuleBool(this->nid, "anti-spawn-experience-orb");
	isAntiCrasher = getModuleBool(this->nid, "anti-crasher");
	auto& funcs = getFunctions();
	if (isAntiXP) 
	{
		auto status = MH_CreateHook(reinterpret_cast<LPVOID>(funcs.ServerNetworkHandler_handle_SpawnExperienceOrbPacket), handleSpawnXPHook, nullptr);
		if (status != 0) 
		{
			nerr("Could not hook to spawn experience orb function!\n MH_Status = " << MH_StatusToString(status)
				<< "\n Function = " << reinterpret_cast<void*>(funcs.ServerNetworkHandler_handle_SpawnExperienceOrbPacket));
		}
	}
	if (isAntiCrasher) {
		auto readFunc = funcs.MovePlayerPacket__read;

		if (!readFunc) {
			this->isAntiCrasher = false;
			nerr("Anti Crasher is not supported on this version.");
			return false;
		}

		MH_CreateHook(reinterpret_cast<LPVOID>(readFunc), MovePlayerPacket_readHook, reinterpret_cast<LPVOID*>(&oMovePlayerRead));

		//nwarn("Anti Crasher setting is experimental and wouldn't work properly.");
	}
	return true;
}

void BasicAntiCheat::disable() 
{
	if (this->isAntiCrasher) {
		
	}
}