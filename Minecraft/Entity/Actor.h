#pragma once
#include "../Pos/AABB.h"


class Actor {
public:
	virtual __int64 hasComponent(__int64 const&); // 0x0
	virtual __int64 reloadHardcoded(__int64, __int64 const&); // 0x1
	virtual __int64 reloadHardcodedClient(__int64, __int64 const&); // 0x2
	virtual __int64 initializeComponents(__int64, __int64 const&); // 0x3
	virtual __int64 reloadComponents(__int64, __int64 const&); // 0x4
	virtual __int64 nullsub_0(void); // 0x5
	virtual __int64 _doInitialMove(void); // 0x6
	virtual ~Actor();
	virtual __int64 reset(void); // 0x8
	virtual __int64 getOnDeathExperience(void); // 0x9
	virtual __int64 getOwnerEntityType(void); // 0xA
	virtual __int64 remove(void); // 0xB
	virtual __int64 setPos(Vec3 const&); // 0xC
	virtual __int64 nullsub_1(void); // 0xD
	virtual __int64 getPredictedMovementValues(void); // 0xE
	virtual __int64 getStateVectorComponent(void); // 0xF
	virtual __int64 getPosOld(void); // 0x10
	virtual __int64 getPosExtrapolated(float); // 0x11
	virtual __int64 getAttachPos(__int64, float); // 0x12
	virtual __int64 getFiringPos(void); // 0x13
	virtual __int64 setRot(Vec2 const&); // 0x14
	virtual __int64 move(__int64&, Vec3 const&); // 0x15
	virtual __int64 move(Vec3 const&); // 0x16
	virtual __int64 getInterpolatedRidingPosition(float); // 0x17
	virtual __int64 getInterpolatedBodyRot(float); // 0x18
	virtual __int64 getInterpolatedHeadRot(float); // 0x19
	virtual __int64 getInterpolatedBodyYaw(float); // 0x1A
	virtual __int64 getYawSpeedInDegreesPerSecond(void); // 0x1B
	virtual __int64 getInterpolatedWalkAnimSpeed(float); // 0x1C
	virtual __int64 nullsub_2(void); // 0x1D
	virtual __int64 checkBlockCollisions(AABB const&, std::function<void(__int64&, Block const&, BlockPos const&, Actor&)>); // 0x1E
	virtual __int64 updateEntityInside(void); // 0x1F
	virtual __int64 updateEntityInside(AABB const&); // 0x20
	virtual __int64 isFireImmune(void); // 0x21
	virtual __int64 nullsub_3(void); // 0x22
	virtual __int64 blockedByShield(__int64 const&, Actor&); // 0x23
	virtual __int64 teleportTo(Vec3 const&, bool, int, int); // 0x24
	virtual __int64 tryTeleportTo(Vec3 const&, bool, bool, int, int); // 0x25
	virtual __int64 chorusFruitTeleport(Vec3&); // 0x26
	virtual __int64 lerpTo(Vec3 const&, Vec2 const&, int); // 0x27
	virtual __int64 lerpMotion(Vec3 const&); // 0x28
	virtual __int64 tryCreateAddActorPacket(void); // 0x29
	virtual __int64 normalTick(void); // 0x2A
	virtual __int64 baseTick(void); // 0x2B
	virtual __int64 rideTick(void); // 0x2C
	virtual __int64 positionRider(Actor&, float); // 0x2D
	virtual __int64 getRidingHeight(void); // 0x2E
	virtual __int64 startRiding(Actor&); // 0x2F
	virtual __int64 addRider(Actor&); // 0x30
	virtual __int64 flagRiderToRemove(Actor&); // 0x31
	virtual __int64 getExitTip(std::string const&, __int64); // 0x32
	virtual __int64 intersects(Vec3 const&, Vec3 const&); // 0x33
	virtual __int64 isFree(Vec3 const&); // 0x34
	virtual __int64 isFree(Vec3 const&, float); // 0x35
	virtual __int64 isInWall(void); // 0x36
	virtual __int64 isInvisible(void); // 0x37
	virtual __int64 canShowNameTag(void); // 0x38
	virtual __int64 nullsub_4(void); // 0x39
	virtual __int64 setNameTagVisible(bool); // 0x3A
	virtual __int64 getNameTag(void); // 0x3B
	virtual __int64 nullsub_5(void); // 0x3C
	virtual __int64 getFormattedNameTag(void); // 0x3D
	virtual __int64 filterFormattedNameTag(__int64 const&); // 0x3E
	virtual __int64 setNameTag(std::string const&); // 0x3F
	virtual __int64 nullsub_6(void); // 0x40
	virtual __int64 setScoreTag(std::string const&); // 0x41
	virtual __int64 getScoreTag(void); // 0x42
	virtual __int64 isInWater(void); // 0x43
	virtual __int64 hasEnteredWater(void); // 0x44
	virtual __int64 isImmersedInWater(void); // 0x45
	virtual __int64 isInLava(void); // 0x46
	virtual __int64 isUnderLiquid(__int64); // 0x47
	virtual __int64 isOverWater(void); // 0x48
	virtual __int64 setBlockMovementSlowdownMultiplier(Vec3 const&); // 0x49
	virtual __int64 resetBlockMovementSlowdownMultiplier(void); // 0x4A
	virtual __int64 getCameraOffset(void); // 0x4B
	virtual __int64 getShadowHeightOffs(void); // 0x4C
	virtual __int64 getShadowRadius(void); // 0x4D
	virtual __int64 getHeadLookVector(float); // 0x4E
	virtual __int64 nullsub_7(void); // 0x4F
	virtual __int64 canSee(Vec3 const&); // 0x50
	virtual __int64 canSee(Actor const&); // 0x51
	virtual __int64 isSkyLit(float); // 0x52
	virtual __int64 getBrightness(float); // 0x53
	virtual __int64 nullsub_8(void); // 0x54
	virtual __int64 nullsub_9(void); // 0x55
	virtual __int64 onAboveBubbleColumn(bool); // 0x56
	virtual __int64 onInsideBubbleColumn(bool); // 0x57
	virtual __int64 isImmobile(void); // 0x58
	virtual __int64 isSilent(void); // 0x59
	virtual __int64 isPickable(void); // 0x5A
	virtual __int64 nullsub_10(void); // 0x5B
	virtual __int64 isSleeping(void); // 0x5C
	virtual __int64 nullsub_11(void); // 0x5D
	virtual __int64 setSneaking(bool); // 0x5E
	virtual __int64 isBlocking(void); // 0x5F
	virtual __int64 isDamageBlocked(__int64 const&); // 0x60
	virtual __int64 isAlive(void); // 0x61
	virtual __int64 isOnFire(void); // 0x62
	virtual __int64 isOnHotBlock(void); // 0x63
	virtual __int64 nullsub_12(void); // 0x64
	virtual __int64 isSurfaceMob(void); // 0x65
	virtual __int64 nullsub_13(void); // 0x66
	virtual __int64 nullsub_14(void); // 0x67
	virtual __int64 nullsub_15(void); // 0x68
	virtual __int64 isAffectedByWaterBottle(void); // 0x69
	virtual __int64 canAttack(Actor*, bool); // 0x6A
	virtual __int64 setTarget(Actor*); // 0x6B
	virtual __int64 nullsub_16(void); // 0x6C
	virtual __int64 nullsub_17(void); // 0x6D
	virtual __int64 attack(Actor&); // 0x6E
	virtual __int64 performRangedAttack(Actor&, float); // 0x6F
	virtual __int64 adjustDamageAmount(int&); // 0x70
	virtual __int64 getEquipmentCount(void); // 0x71
	virtual __int64 setOwner(ActorUniqueID); // 0x72
	virtual __int64 setSitting(bool); // 0x73
	virtual __int64 nullsub_18(void); // 0x74
	virtual __int64 nullsub_19(void); // 0x75
	virtual __int64 getInventorySize(void); // 0x76
	virtual __int64 getEquipSlots(void); // 0x77
	virtual __int64 getChestSlots(void); // 0x78
	virtual __int64 setStanding(bool); // 0x79
	virtual __int64 canPowerJump(void); // 0x7A
	virtual __int64 setCanPowerJump(bool); // 0x7B
	virtual __int64 isJumping(void); // 0x7C
	virtual __int64 isEnchanted(void); // 0x7D
	virtual __int64 nullsub_20(void); // 0x7E
	virtual __int64 nullsub_21(void); // 0x7F
	virtual __int64 shouldRender(void); // 0x80
	virtual __int64 isInvulnerableTo(__int64 const&); // 0x81
	virtual __int64 getBlockDamageCause(Block const&); // 0x82
	virtual __int64 actuallyHurt(int, __int64 const&, bool); // 0x83
	virtual __int64 animateHurt(void); // 0x84
	virtual __int64 doFireHurt(int); // 0x85
	virtual __int64 onLightningHit(void); // 0x86
	virtual __int64 onBounceStarted(BlockPos const&, Block const&); // 0x87
	virtual __int64 feed(int); // 0x88
	virtual __int64 handleEntityEvent(__int64, int); // 0x89
	virtual __int64 getPickRadius(void); // 0x8A
	virtual __int64 getActorRendererId(void); // 0x8B
	virtual __int64 spawnAtLocation(ItemStack const&, float); // 0x8C
	virtual __int64 spawnAtLocation(Block const&, int, float); // 0x8D
	virtual __int64 spawnAtLocation(Block const&, int); // 0x8E
	virtual __int64 spawnAtLocation(int, int, float); // 0x8F
	virtual __int64 spawnAtLocation(int, int); // 0x90
	virtual __int64 despawn(void); // 0x91
	virtual __int64 killed(Actor&); // 0x92
	virtual __int64 awardKillScore(Actor&, int); // 0x93
	virtual __int64 setArmor(__int64, ItemStack const&); // 0x94
	virtual __int64 getArmor(__int64); // 0x95
	virtual __int64 getArmor__int64InSlot(__int64); // 0x96
	virtual __int64 getArmorMaterialTextureTypeInSlot(__int64); // 0x97
	virtual __int64 getArmorColorInSlot(__int64, int); // 0x98
	virtual __int64 getEquippedSlot(__int64); // 0x99
	virtual __int64 setEquippedSlot(__int64, ItemStack const&); // 0x9A
	virtual __int64 getSelectedItem(void); // 0x9B
	virtual __int64 setCarriedItem(ItemStack const&); // 0x9C
	virtual __int64 setOffhandSlot(ItemStack const&); // 0x9D
	virtual __int64 getEquippedTotem(void); // 0x9E
	virtual __int64 consumeTotem(void); // 0x9F
	virtual __int64 save(CompoundTag&); // 0xA0
	virtual __int64 saveWithoutId(CompoundTag&); // 0xA1
	virtual __int64 load(CompoundTag const&, __int64&); // 0xA2
	virtual __int64 loadLinks(CompoundTag const&, std::vector<__int64>&, __int64&); // 0xA3
	virtual __int64 getEntityTypeId(void); // 0xA4
	virtual __int64 nullsub_22(void); // 0xA5
	virtual __int64 getSourceUniqueID(void); // 0xA6
	virtual __int64 setOnFire(int); // 0xA7
	virtual __int64 extinguishFire(void); // 0xA8
	virtual __int64 thawFreezeEffect(void); // 0xA9
	virtual __int64 canFreeze(void); // 0xAA
	virtual __int64 isWearingLeatherArmor(void); // 0xAB
	virtual __int64 getHandleWaterAABB(void); // 0xAC
	virtual __int64 handleInsidePortal(BlockPos const&); // 0xAD
	virtual __int64 nullsub_23(void); // 0xAE
	virtual __int64 getPortalWaitTime(void); // 0xAF
	virtual __int64 getDimensionId(void); // 0xB0
	virtual __int64 nullsub_24(void); // 0xB1
	virtual __int64 nullsub_25(void); // 0xB2
	virtual __int64 changeDimension(__int64, bool); // 0xB3
	virtual __int64 getSourceUniqueID(void); // 0xB4
	virtual __int64 checkFallDamage(float, bool); // 0xB5
	virtual __int64 causeFallDamage(float, float, __int64); // 0xB6
	virtual __int64 handleFallDistanceOnServer(float, float, bool); // 0xB7
	virtual __int64 playSynchronizedSound(__int64, Vec3 const&, int, bool); // 0xB8
	virtual __int64 playSynchronizedSound(__int64, Vec3 const&, Block const&, bool); // 0xB9
	virtual __int64 onSynchedDataUpdate(int); // 0xBA
	virtual __int64 canAddRider(Actor&); // 0xBB
	virtual __int64 nullsub_26(void); // 0xBC
	virtual __int64 nullsub_27(void); // 0xBD
	virtual __int64 inCaravan(void); // 0xBE
	virtual __int64 nullsub_28(void); // 0xBF
	virtual __int64 tickLeash(void); // 0xC0
	virtual __int64 nullsub_29(void); // 0xC1
	virtual __int64 nullsub_30(void); // 0xC2
	virtual __int64 stopRiding(bool, bool, bool); // 0xC3
	virtual __int64 startSwimming(void); // 0xC4
	virtual __int64 stopSwimming(void); // 0xC5
	virtual __int64 buildDebugInfo(std::string&); // 0xC6
	virtual __int64 getCommandPermissionLevel(void); // 0xC7
	virtual __int64 getMutable__int64(__int64 const&); // 0xC8
	virtual __int64 get__int64(__int64 const&); // 0xC9
	virtual __int64 getDeathTime(void); // 0xCA
	virtual __int64 heal(int); // 0xCB
	virtual __int64 isInvertedHealAndHarm(void); // 0xCC
	virtual __int64 canBeAffected(__int64 const&); // 0xCD
	virtual __int64 canBeAffected(int); // 0xCE
	virtual __int64 canBeAffectedByArrow(__int64 const&); // 0xCF
	virtual __int64 onEffectAdded(__int64&); // 0xD0
	virtual __int64 onEffectUpdated(__int64 const&); // 0xD1
	virtual __int64 onEffectRemoved(__int64&); // 0xD2
	virtual __int64 getAnimationComponent(void); // 0xD3
	virtual __int64 openContainerComponent(Player&); // 0xD4
	virtual __int64 swing(void); // 0xD5
	virtual __int64 useItem(ItemStackBase&, __int64, bool); // 0xD6
	virtual __int64 nullsub_31(void); // 0xD7
	virtual __int64 nullsub_32(void); // 0xD8
	virtual __int64 getDebugText(std::vector<std::string>&); // 0xD9
	virtual __int64 getMapDecorationRotation(void); // 0xDA
	virtual __int64 getRiderYRotation(Actor const&); // 0xDB
	virtual __int64 getYHeadRot(void); // 0xDC
	virtual __int64 isWorldBuilder(void); // 0xDD
	virtual __int64 isCreative(void); // 0xDE
	virtual __int64 isAdventure(void); // 0xDF
	virtual __int64 add(ItemStack&); // 0xE0
	virtual __int64 drop(ItemStack const&, bool); // 0xE1
	virtual __int64 getInteraction(Player&, __int64&, Vec3 const&); // 0xE2
	virtual __int64 nullsub_33(void); // 0xE3
	virtual __int64 nullsub_34(void); // 0xE4
	virtual __int64 setSize(float, float); // 0xE5
	virtual __int64 getLifeSpan(void); // 0xE6
	virtual __int64 onOrphan(void); // 0xE7
	virtual __int64 wobble(void); // 0xE8
	virtual __int64 wasHurt(void); // 0xE9
	virtual __int64 startSpinAttack(void); // 0xEA
	virtual __int64 stopSpinAttack(void); // 0xEB
	virtual __int64 setDamageNearbyMobs(bool); // 0xEC
	virtual __int64 nullsub_35(void); // 0xED
	virtual __int64 reloadLootTable(__int64 const&); // 0xEE
	virtual __int64 reloadLootTable(void); // 0xEF
	virtual __int64 getLootTable(void); // 0xF0
	virtual __int64 nullsub_36(void); // 0xF1
	virtual __int64 nullsub_37(void); // 0xF2
	virtual __int64 kill(void); // 0xF3
	virtual __int64 die(__int64 const&); // 0xF4
	virtual __int64 shouldTick(void); // 0xF5
	virtual __int64 createMovementProxy(void); // 0xF6
	virtual __int64 getMovementProxy(void); // 0xF7
	virtual __int64 getNextStep(float); // 0xF8
	virtual __int64 updateEntitySpecificMolangVariables(__int64&); // 0xF9
	virtual __int64 nullsub_38(void); // 0xFA
	virtual __int64 nullsub_39(void); // 0xFB
	virtual __int64 outOfWorld(void); // 0xFC
	virtual __int64 _hurt(__int64 const&, int, bool, bool); // 0xFD
	virtual __int64 markHurt(void); // 0xFE
	virtual __int64 _getAnimationComponent(std::shared_ptr<__int64>&, __int64); // 0xFF
	virtual __int64 readAdditionalSaveData(CompoundTag const&, __int64&); // 0x100
	virtual __int64 addAdditionalSaveData(class CompoundTag&); // 0x101
	virtual __int64 _playStepSound(BlockPos const&, Block const&); // 0x102
	virtual __int64 _playFlySound(class BlockPos const&, Block const&); // 0x103
	virtual __int64 nullsub_40(void); // 0x104
	virtual __int64 checkInsideBlocks(float); // 0x105
	virtual __int64 pushOutOfBlocks(Vec3 const&); // 0x106
	virtual __int64 updateWaterState(void); // 0x107
	virtual __int64 doWaterSplashEffect(void); // 0x108
	virtual __int64 spawnTrailBubbles(void); // 0x109
	virtual __int64 updateInsideBlock(void); // 0x10A
	virtual __int64 _removeRider(class ActorUniqueID const&, bool, bool, bool); // 0x10B
	virtual __int64 _onSizeUpdated(void); // 0x10C
	virtual __int64 nullsub_41(void); // 0x10D
};

class Mob : public Actor {
	virtual __int64 knockback(Actor*, int, float, float, float, float, float); // 0x10E
	virtual __int64 resolveDeathLoot(int, __int64 const&); // 0x10F
	virtual __int64 nullsub_42(void); // 0x110
	virtual __int64 setSleeping(bool); // 0x111
	virtual __int64 setSprinting(bool); // 0x112
	virtual __int64 playAmbientSound(void); // 0x113
	virtual __int64 getAmbientSound(void); // 0x114
	virtual __int64 getHurtSound(void); // 0x115
	virtual __int64 getDeathSound(void); // 0x116
	virtual __int64 getAmbientSoundPostponeTicks(void); // 0x117
	virtual __int64 getAmbientSoundPostponeTicksRange(void); // 0x118
	virtual __int64 getItemInHandIcon(ItemStack const&, int); // 0x119
	virtual __int64 getSpeed(void); // 0x11A
	virtual __int64 setSpeed(float); // 0x11B
	virtual __int64 getJumpPower(void); // 0x11C
	virtual __int64 hurtEffects(__int64 const&, int, bool, bool); // 0x11D
	virtual __int64 getMeleeWeaponDamageBonus(Mob*); // 0x11E
	virtual __int64 getMeleeKnockbackBonus(void); // 0x11F
	virtual __int64 travel(__int64&, float, float, float); // 0x120
	virtual __int64 travel(float, float, float); // 0x121
	virtual __int64 applyFinalFriction(float, bool); // 0x122
	virtual __int64 updateWalkAnim(void); // 0x123
	virtual __int64 aiStep(__int64&); // 0x124
	virtual __int64 aiStep(void); // 0x125
	virtual __int64 pushActors(void); // 0x126
	virtual __int64 lookAt(Actor*, float, float); // 0x127
	virtual __int64 isLookingAtAnEntity(void); // 0x128
	virtual __int64 checkSpawnRules(bool); // 0x129
	virtual __int64 checkSpawnObstruction(void); // 0x12A
	virtual __int64 getAttackAnim(float); // 0x12B
	virtual __int64 getItemUseDuration(void); // 0x12C
	virtual __int64 getItemUseStartupProgress(void); // 0x12D
	virtual __int64 getItemUseIntervalProgress(void); // 0x12E
	virtual __int64 getItemuseIntervalAxis(void); // 0x12F
	virtual __int64 getTimeAlongSwing(void); // 0x130
	virtual __int64 nullsub_43(void); // 0x131
	virtual __int64 getMaxHeadXRot(void); // 0x132
	virtual __int64 getLastHurtByMob(void); // 0x133
	virtual __int64 setLastHurtByMob(Mob*); // 0x134
	virtual __int64 getLastHurtByPlayer(void); // 0x135
	virtual __int64 setLastHurtByPlayer(Player*); // 0x136
	virtual __int64 getLastHurtMob(void); // 0x137
	virtual __int64 setLastHurtMob(Actor*); // 0x138
	virtual __int64 nullsub_44(void); // 0x139
	virtual __int64 doHurtTarget(Actor*); // 0x13A
	virtual __int64 nullsub_45(void); // 0x13B
	virtual __int64 leaveCaravan(void); // 0x13C
	virtual __int64 joinCaravan(Mob*); // 0x13D
	virtual __int64 hasCaravanTail(void); // 0x13E
	virtual __int64 getCaravanHead(void); // 0x13F
	virtual __int64 getArmorValue(void); // 0x140
	virtual __int64 getArmorCoverPercentage(void); // 0x141
	virtual __int64 hurtArmor(__int64 const&, int, __int64 const&); // 0x142
	virtual __int64 hurtArmor(__int64 const&, int); // 0x143
	virtual __int64 hurt__int64(__int64 const&, int, __int64); // 0x144
	virtual __int64 setDamagedArmor(__int64, ItemStack const&); // 0x145
	virtual __int64 nullsub_46(void); // 0x146
	virtual __int64 sendArmor(__int64 const&); // 0x147
	virtual __int64 containerChanged(int); // 0x148
	virtual __int64 updateEquipment(void); // 0x149
	virtual __int64 clearEquipment(void); // 0x14A
	virtual __int64 getAllArmor(void); // 0x14B
	virtual __int64 getAllArmorID(void); // 0x14C
	virtual __int64 getAllHand(void); // 0x14D
	virtual __int64 getAllEquipment(void); // 0x14E
	virtual __int64 getArmorTypeHash(void); // 0x14F
	virtual __int64 dropEquipmentOnDeath(void); // 0x150
	virtual __int64 dropEquipmentOnDeath(__int64 const&, int); // 0x151
	virtual __int64 nullsub_47(void); // 0x152
	virtual __int64 nullsub_48(void); // 0x153
	virtual __int64 getDamageAfterMagicAbsorb(__int64 const&, int); // 0x154
	virtual __int64 createAIGoals(void); // 0x155
	virtual __int64 nullsub_49(void); // 0x156
	virtual __int64 setItemSlot(__int64, ItemStack const&); // 0x157
	virtual __int64 setTransitioningSitting(bool); // 0x158
	virtual __int64 attackAnimation(Actor*, float); // 0x159
	virtual __int64 nullsub_50(void); // 0x15A
	virtual __int64 nullsub_51(void); // 0x15B
	virtual __int64 nullsub_52(void); // 0x15C
	virtual __int64 nullsub_53(void); // 0x15D
	virtual __int64 ascendLadder(void); // 0x15E
	virtual __int64 ascendScaffolding(void); // 0x15F
	virtual __int64 ascendScaffolding(void); // 0x160
	virtual __int64 descendScaffolding(void); // 0x161
	virtual __int64 canAscendCurrentBlockByJumping(void); // 0x162
	virtual __int64 dropContainer(void); // 0x163
	virtual __int64 initBodyControl(void); // 0x164
	virtual __int64 jumpFromGround(__int64&); // 0x165
	virtual __int64 jumpFromGround(void); // 0x166
	virtual __int64 nullsub_54(void); // 0x167
	virtual __int64 newServerAiStep(void); // 0x168
	virtual __int64 nullsub_55(void); // 0x169
	virtual __int64 getDamageAfterEnchantReduction(__int64 const&, int); // 0x16A
	virtual __int64 getDamageAfterArmorAbsorb(__int64 const&, int); // 0x16B
	virtual __int64 dropBags(void); // 0x16C
	virtual __int64 tickDeath(void); // 0x16D
	virtual __int64 updateGliding(void); // 0x16E
	virtual __int64 nullsub_56(void); // 0x16F
};