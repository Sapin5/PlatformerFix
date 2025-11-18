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
	

	/// <summary>
	/// Modify the strength of gravity applied on the actor
	/// </summary>
	/// <param name="gravityValue"></param>
	void setGravity(float gravityValue);
	

	/// <summary>
	/// Enable or disable gravity on the actor
	/// </summary>
	/// <param name="enable"></param>
	void toggleGravity(bool enable);


	/// <summary>
	/// Applies gravity on actor
	/// </summary>
	void applyGravity();


	/// <summary>
	/// Sets terminal velocity which will limit the speed at which player falls
	/// </summary>
	/// <param name="terminalVelocity"></param>
	void setTerminalVelocity(float terminalVelocity);

	Base() = default;

	Base(bool enableGravity) {
		this->enableGravity = enableGravity;
	}
};

#endif // !BASECLASS_H