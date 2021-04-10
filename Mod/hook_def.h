#pragma once
typedef int InventoryTransactionError;

class Player {
public:
	uintptr_t** vtable;
};

class ItemUseInventoryTransaction {
public:
	uintptr_t** vtable;
	int transactionType;
	int t2;
};

typedef void(__cdecl* Mob_knockback)(void*, void*, float, float, float, float, float);
typedef int(*ItemUseInventoryTransactionHandle)(ItemUseInventoryTransaction*, Player*, bool);