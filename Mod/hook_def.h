#pragma once

class Player {
public:
	uintptr_t** vtable;
};

class ItemUseInventoryTransaction {
public:
	uintptr_t** vtable;
};


struct Vec3 {
	float x;
	float y;
	float z;
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

typedef void(__cdecl* Mob_knockback)(void*, void*, float, float, float, float, float);
typedef int(*ItemUseInventoryTransactionHandle)(ItemUseInventoryTransaction*, Player*, bool);

typedef void(__cdecl* MovePlayerHandler)(void*, NetworkIdentifier* const&, MovePlayerPacket* const&);