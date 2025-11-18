#ifndef BASECLASS_H
#define BASECLASS_H

#include "raylib.h"

class Base {
private:
	// Real world grav is about 9.8f
	float gravity{ 300.0f };
	bool enableGravity{ true };
	float terminalVelocity{ 250.0f };
public:
	Vector2 velocity{ 0,0 };
	
	void setGravity(float gravityValue);
	
	void toggleGravity(bool enable);

	void applyGravity();

	void setTerminalVelocity(float terminalVelocity);

	Base() = default;

	Base(bool enableGravity) {
		this->enableGravity = enableGravity;
	}
};

#endif // !BASECLASS_H