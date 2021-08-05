#pragma once

enum class Actor_InitializationMethod {};

class NetworkIdentifier {
};

struct Tick {
};

#include "../Minecraft/Common.h"

#include "../Minecraft/Block/Block.h"
#include "../Minecraft/Entity/Player.h"

#include "../Minecraft/Item/ItemStack.h"

#include "../Minecraft/Pos/AABB.h"
#include "../Minecraft/Pos/Vector.h"

#include "../Minecraft/Network/StreamReadResult.h"

typedef void(__cdecl* Mob_knockback)(void*, void*, float, float, float, float, float);
typedef void(__cdecl* set_pos_t)(Actor*, Vec3&);
typedef __int64(__cdecl* base_tick_t)(Actor*);
typedef ItemDescriptor(__cdecl* get_descriptor_t)(ItemStackBase*);
typedef bool(__cdecl* itemstack_useon_t)(ItemStack*, Actor*, int, int, int, byte, float, float, float);