#include "BaseClass.hpp"
#include <iostream>

/// <summary>
/// Update gravity applied to actor
/// </summary>
/// <param name="gravityValue"></param>
void Base::setGravity(float gravityValue) {
	this->gravity = gravityValue;
}

/// <summary>
/// Toggle gravity on/off
/// </summary>
/// <param name="enable"></param>
void Base::toggleGravity(bool enable) {
	this->enableGravity = enable;
}

/// <summary>
/// When called applies gravity onto given actor.
/// Also stops actor from falling faster than terminal velocity
/// </summary>
void Base::applyGravity() {
	if (enableGravity) {
		velocity.y += gravity * GetFrameTime();
		// std::cout << velocity.y << std::endl;
		if (velocity.y > terminalVelocity) velocity.y = terminalVelocity;
	}
}

/// <summary>
/// Update terminal velocity for actors
/// Set to 150 by default
/// </summary>
/// <param name="terminalVelocity"></param>
void Base::setTerminalVelocity(float terminalVelocity) {
	this->terminalVelocity = terminalVelocity;
}