#ifndef BASECLASS_H
#define BASECLASS_H

#include "raylib.h"

class Base {
private:
	float gravity{ 9.8f };
	bool enableGravity{ true };
public:
	Vector2 velocity{ 0,0 };
	
	void setGravity(float gravityValue);
	
	void toggleGravity(bool enable);

	void applyGravity();

	Base() = default;

	Base(bool enableGravity) {
		this->enableGravity = enableGravity;
	}
};

#endif // !BASECLASS_H