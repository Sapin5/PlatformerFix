#ifndef BASECLASS_H
#define BASECLASS_H

#include "raylib.h"

class Base {
private:
	float gravity{ 9.8f };
	bool enableGravity{ true };
	Vector2 velocity{ 0,0 };
public:
	void setGravity(float gravityValue);
	
	void toggleGravity(bool enable);

	void applyGravity();
};

#endif // !BASECLASS_H