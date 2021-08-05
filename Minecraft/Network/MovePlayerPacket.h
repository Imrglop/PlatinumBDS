#pragma once
#include "Packet.h"
#include "../Pos/Vector.h"

class MovePlayerPacket : Packet {
public:
	__int64 entRuntimeId;
	Vec3 position;
	Vec2 rotation;
	// other stuff
};