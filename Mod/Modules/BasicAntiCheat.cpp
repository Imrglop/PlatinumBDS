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

MovePlayerHandler handleMovePlayer;
player_tickworld_t tickPlayer;
set_pos_t setActorPos;
base_tick_t baseTick;
get_descriptor_t getItemDescriptor;

bool __cdecl useItemStackHook(ItemStack* item, Actor*, int, int, int, byte, float, float, float) {
	llog("itemStack: " << item);
	ItemStackBase* base = (ItemStackBase*)item;
	llog("itemstackbase: " << base);
	ItemDescriptor desc = getItemDescriptor(base);
	llog("<logging descriptor>");
	llog("block: " << desc.block);
	llog("damage: " << desc.damage);
	llog("isItem: " << desc.isItem);
	llog("Item: " << desc.item);

	return true;
}

void __cdecl handleMovePlayerPacketHook(void* _this, NetworkIdentifier* const& ni, MovePlayerPacket* const& packet) 
{
	handleMovePlayer(_this, ni, packet);
}

void __cdecl handleSpawnXPHook(void* _this, NetworkIdentifier* const& ni, void* const& _SpawnExperienceOrb_packet)
{
}

const float maxTp = 3e6f;
__int64 __cdecl baseTickHook(Actor* _this) {
	return baseTick(_this);
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
		vftable_t vtPlayer = reinterpret_cast<vftable_t>(funcs.Player_vtable);
		if (vtPlayer == NULL) {
			this->isAntiCrasher = false;
			nerr("Anti Crasher is not supported on this version.");
			return false;
		}
		nwarn("Anti Crasher setting is experimental and wouldn't work properly.");
		auto& tickFunc = vtPlayer[41];
		int status = vh::hook(reinterpret_cast<LPVOID*>(&tickFunc), baseTickHook, reinterpret_cast<LPVOID*>(baseTick));
		if (status != 0)
		{
			nerr("Could not hook to player normalTick function!\n VH_Status = " << vh::statusToString(status)
				<< "\n Function = " << reinterpret_cast<void*>(tickFunc));
		}
	}
	return true;
}

void BasicAntiCheat::disable() 
{
	if (this->isAntiCrasher) {
		vftable_t vtPlayer = reinterpret_cast<vftable_t>(main::getFunctions().Player_vtable);
		auto tickFunc = vtPlayer[41];
		//vh::unhook(reinterpret_cast<LPVOID*>(tickFunc));
	}
}