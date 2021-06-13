#pragma once
#include "Vector.h"

// bounding box
struct AABB {
	Vec3 upper;
	Vec3 lower;
	bool isZero;
	char pad[3];
};