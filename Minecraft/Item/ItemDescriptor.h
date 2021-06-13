#pragma once
#include "Item.h"

class ItemDescriptor {
public:
	Item* item;
	Block* block;
	short damage;
	bool isItem;
};