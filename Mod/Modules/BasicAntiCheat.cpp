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

MovePlayerHandler handleMovePlayer = NULL;
//SpawnXPHandler spawnXPHandler = NULL;

void __cdecl handleMovePlayerPacketHook(void* _this, NetworkIdentifier* const& ni, MovePlayerPacket* const& packet) 
{
	//ldbg("Move: " << packet);
	handleMovePlayer(_this, ni, packet);
}

void __cdecl handleSpawnXPHook(void* _this, NetworkIdentifier* const& ni, void* const& _SpawnExperienceOrb_packet)
{
	// TODO: check if will cause memory leak somehow
}

bool BasicAntiCheat::enable() 
{
	using namespace settings;
	using namespace main;
	isAntiXP = getModuleBool(this->nid, "anti-spawn-experience-orb");
	auto& funcs = getFunctions();
	if (isAntiXP) 
	{
		auto status = MH_CreateHook(reinterpret_cast<LPVOID>(funcs.ServerNetworkHandler_handle_SpawnExperienceOrbPacket), handleSpawnXPHook, nullptr);
		if (status != 0) 
		{
			lerr("Could not hook to spawn experience orb function!\n MH_Status = " << MH_StatusToString(status)
				<< "\n Function = " << reinterpret_cast<void*>(funcs.ServerNetworkHandler_handle_SpawnExperienceOrbPacket));
		}
	}
	return true;
}

void BasicAntiCheat::disable() 
{
}