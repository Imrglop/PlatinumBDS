#pragma once

#include <sstream>

enum class Actor_InitializationMethod {};

typedef uintptr_t** vftable_t;

struct Vec3 {
	float x;
	float y;
	float z;
	bool isZero;
	char pad[0x3];

	inline std::string toString() {
		return (std::ostringstream() << this->x << ", " << this->y << ", " << this->z).str();
	}
};

class Actor {
private:
	virtual bool __cdecl hasComponent(class HashedString const&);
	virtual void __cdecl filler_000();
	virtual void __cdecl reloadHardcodedClient(Actor_InitializationMethod, class VariantParameterList const&);
	virtual void __cdecl initializeComponents(Actor_InitializationMethod, VariantParameterList const&);
	virtual void __cdecl reloadComponents(Actor_InitializationMethod, VariantParameterList const&);
	virtual void __cdecl _serverInitItemStackIds();
	virtual void __cdecl _doInitialMove();
	virtual void __cdecl destructor(unsigned int);
	virtual void __cdecl reset();
	virtual int __cdecl getOnDeathExperience();
	virtual enum ActorType __cdecl getOwnerEntityType();
public:

	virtual void __cdecl remove();
	virtual void __cdecl setPos(Vec3 const&); // 12
	virtual void __cdecl filler_001();
	virtual enum PredictedMovementValues const& __cdecl getPredictedMovementValues();
	//virtual class StateVectorComponent const& __cdecl getStateVectorComponent();
	virtual Vec3 getPos();
};

typedef Actor Player;
class ItemUseInventoryTransaction {
public:
	uintptr_t** vtable;
};

struct AABB {
	Vec3 upper;
	Vec3 lower;
	bool isZero;
	char pad[3];
};

struct Vec2 {
	float x;
	float y;
};

struct PYHY {
	float pitch;
	float yaw;
	float headYaw;
};

// Packet

class MovePlayerPacket {
public:
	unsigned __int64 entityRuntimeId;

	Vec3 position;
	PYHY rotation;

	byte mode;
	bool onGround;

	float ridingEntityRuntimeId;
	signed __int32 teleportationCause; // Only if mode is 2
	unsigned char entityType; // Only if mode is 2
};
class NetworkIdentifier {
};

struct Tick {

};

typedef void(__cdecl* Mob_knockback)(void*, void*, float, float, float, float, float);
typedef int(*ItemUseInventoryTransactionHandle)(ItemUseInventoryTransaction*, Player*, bool);
typedef int(__cdecl* player_tickworld_t)(Player*, Tick*);
typedef void(__cdecl* set_pos_t)(Actor*, Vec3&);
typedef __int64(__cdecl* base_tick_t)(Actor*);
typedef void(__cdecl* MovePlayerHandler)(void*, NetworkIdentifier* const&, MovePlayerPacket* const&);