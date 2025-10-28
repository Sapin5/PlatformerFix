#include "BaseClass.hpp"

void Base::setGravity(float gravityValue) {
	this->gravity = gravityValue;
}

void Base::toggleGravity(bool enable) {
	this->enableGravity = enable;
}

void Base::applyGravity() {
	if (enableGravity) {
		velocity.y += gravity * GetFrameTime();
	}
}