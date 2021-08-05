#pragma once
#include <sstream>

struct BlockPos {
	int x, y, z;
};

struct Vec3 {
	float x;
	float y;
	float z;

	inline std::string toString() {
		return (std::stringstream() << this->x << ", " << this->y << ", " << this->z).str();
	}
};

struct Vec2 {
	float x;
	float y;
};