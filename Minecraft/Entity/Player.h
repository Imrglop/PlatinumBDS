#pragma once
#include "Actor.h"
#include "../Pos/Vector.h"
#include <functional>

class Player : public Mob {
	// EatVtable.js
	virtual __int64 prepareRegion(/*ChunkSource&*/); // 0x170
	virtual __int64 destroyRegion(void); // 0x171
	virtual __int64 suspendRegion(void); // 0x172
	virtual __int64 nullsub_57(void); // 0x173
	virtual __int64 _fireWillChangeDimension(void); // 0x174
	virtual __int64 _fireDimensionChanged(void); // 0x175
	virtual __int64 nullsub_58(void); // 0x176
	virtual __int64 tickWorld(Tick const&); // 0x177
	virtual __int64 nullsub_59(void); // 0x178
	virtual __int64 getTickingOffsets(void); // 0x179
	virtual __int64 moveView(void); // 0x17A
	virtual __int64 setName(std::string const&); // 0x17B
	virtual __int64 nullsub_60(void); // 0x17C
	virtual __int64 nullsub_61(void); // 0x17D
	virtual __int64 nullsub_62(void); // 0x17E
	virtual __int64 respawn(void); // 0x17F
	virtual __int64 nullsub_63(void); // 0x180
	virtual __int64 resetPos(bool); // 0x181
	virtual __int64 nullsub_64(void); // 0x182
	virtual __int64 hasResource(int); // 0x183
	virtual __int64 completeUsingItem(void); // 0x184
	virtual __int64 setPermissions(/*CommandPermissionLevel*/); // 0x185
	virtual __int64 startDestroying(void); // 0x186
	virtual __int64 stopDestroying(void); // 0x187
	virtual __int64 nullsub_65(void); // 0x188
	virtual __int64 nullsub_66(void); // 0x189
	virtual __int64 nullsub_67(void); // 0x18A
	virtual __int64 canOpenContainerScreen(void); // 0x18B
	virtual __int64 nullsub_68(void); // 0x18C
	virtual __int64 nullsub_69(void); // 0x18D
	virtual __int64 nullsub_70(void); // 0x18E
	virtual __int64 nullsub_71(void); // 0x18F
	virtual __int64 nullsub_72(void); // 0x190
	virtual __int64 nullsub_73(void); // 0x191
	virtual __int64 nullsub_74(void); // 0x192
	virtual __int64 nullsub_75(void); // 0x193
	virtual __int64 startSleepInBed(struct BlockPos const&); // 0x194
	virtual __int64 stopSleepInBed(bool, bool); // 0x195
	virtual __int64 canStartSleepInBed(void); // 0x196
	virtual __int64 getSleepTimer(void); // 0x197
	virtual __int64 getPreviousTickSleepTimer(void); // 0x198
	virtual __int64 nullsub_76(void); // 0x199
	virtual __int64 nullsub_77(void); // 0x19A
	virtual __int64 nullsub_78(void); // 0x19B
	virtual __int64 nullsub_79(void); // 0x19C
	virtual __int64 nullsub_80(void); // 0x19D
	virtual __int64 nullsub_81(void); // 0x19E
	virtual __int64 registerTrackedBoss(__int64); // 0x19F
	virtual __int64 unRegisterTrackedBoss(__int64); // 0x1A0
	virtual __int64 setPlayerGameType(__int64); // 0x1A1
	virtual __int64 initHUDContainerManager(void); // 0x1A2
	virtual __int64 _crit(Actor&); // 0x1A3
	virtual __int64 getEventing(void); // 0x1A4
	virtual __int64 nullsub_82(void); // 0x1A5
	virtual __int64 sendEventPacket(/*EventPacket&*/__int64); // 0x1A6
	virtual __int64 addExperience(int); // 0x1A7
	virtual __int64 addLevels(int); // 0x1A8
	virtual __int64 nullsub_83(void); // 0x1A9
	virtual __int64 nullsub_84(void); // 0x1AA
	virtual __int64 inventoryChanged(/*Container&*/__int64, int, ItemStack const&, ItemStack const&, bool); // 0x1AB
	virtual __int64 nullsub_85(void); // 0x1AC
	virtual __int64 deleteContainerManager(void); // 0x1AD
	virtual __int64 setFieldOfViewModifier(float); // 0x1AE
	virtual __int64 nullsub_86(void); // 0x1AF
	virtual __int64 nullsub_87(void); // 0x1B0
	virtual __int64 nullsub_89(void); // 0x1B1
	virtual __int64 nullsub_90(void); // 0x1B2
	virtual __int64 nullsub_91(void); // 0x1B3
	virtual __int64 startCooldown(Item const*); // 0x1B4
	virtual __int64 getItemCooldownLeft(std::string const&); // 0x1B5
	virtual __int64 isItemInCooldown(std::string const&); // 0x1B6
	virtual __int64 nullsub_92(void); // 0x1B7
	virtual __int64 nullsub_93(void); // 0x1B8
	virtual __int64 nullsub_94(void); // 0x1B9
	virtual __int64 nullsub_96(void); // 0x1BA
	virtual __int64 nullsub_98(void); // 0x1BB
	virtual __int64 nullsub_100(void); // 0x1BC
	virtual __int64 nullsub_102(void); // 0x1BD
	virtual __int64 nullsub_103(void); // 0x1BE
	virtual __int64 onMovePlayerPacketNormal(Vec3 const&, Vec2 const&, float); // 0x1BF
};