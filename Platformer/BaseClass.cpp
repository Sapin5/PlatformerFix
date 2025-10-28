#include "BaseClass.hpp"

void Base::setGravity(float gravityValue) {
	this->gravity = gravityValue;
}

void Base::toggleGravity(bool enable) {
	this->enableGravity = enable;
}

void Base::applyGravity() {
	if (enableGravity) {
		velocity.y = velocity.y - gravity * (GetFrameTime() * GetFrameTime() / 2);
	}
}