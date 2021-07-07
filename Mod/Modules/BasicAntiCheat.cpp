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

struct IActorMovementProxy {};
//void Player::move(Player* __hidden this, struct IActorMovementProxy*, const struct Vec3*)
typedef void(__fastcall* player_move_t)(Player*, IActorMovementProxy*, Vec3*);
player_move_t oPlayerMove;

static float maxTp = 3e6f;

void Player_moveF(Player* _this, IActorMovementProxy* proxy, Vec3* newPos) {
	if (newPos->x >= maxTp ||
		newPos->y >= maxTp ||
		newPos->z >= maxTp) {
		
	}
}


bool BasicAntiCheat::enable() 
{
	using namespace settings;
	using namespace main;
	isAntiXP = getModuleBool(this->nid, "anti-spawn-experience-orb");
	isAntiCrasher = getModuleBool(this->nid, "anti-crasher");
	auto& funcs = getFunctions();
	getItemDescriptor = (get_descriptor_t)(main::getData().base + 0xA11840);
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
		//vftable_t vtPlayer = reinterpret_cast<vftable_t>(funcs.Player_vtable);
		//void* playerMoveFunc = reinterpret_cast<void*>(funcs.Plaer_move);
		if (false) {
			this->isAntiCrasher = false;
			nerr("Anti Crasher is not supported on this version.");
			return false;
		}

		nwarn("Anti Crasher setting is experimental and wouldn't work properly.");
	}
	return true;
}

void BasicAntiCheat::disable() 
{
	if (this->isAntiCrasher) {
		
	}
}