#include "Actor.hpp"
#include <iostream>

void Actor::drawActor() {
	this->collider.createCollider();
	if (blankSprite) {
		DrawRectangle(static_cast<int>(position.x), static_cast<int>(position.y), scaleX, scaleY, GREEN);
	}
}

void Actor::spriteEnabled(bool value) {
	blankSprite = value;
}

void Actor::setAnimation(AnimationHandler* sprites) {
	this->sprites = sprites;
}

std::string Actor::getTag() {
	return this->tag;
}

void Actor::applyForce(Vector2 force) {
	this->velocity.x += force.x;
	this->velocity.y += force.y;
}

void Actor::update() {
	applyGravity();
	this->position.x += velocity.x*GetFrameTime();
	this->position.y += velocity.y*GetFrameTime();

	collider.updatePosition(position);
}

void Actor::collisionCheck(Collider& other) {
	std::vector<float> adjustments{};
	bool collided{ collider.checkCollisions(other)};

	if (collided) {
		adjustments = { collider.adjustPostion(other) };
		if (adjustments[0] < adjustments[1])
		{
			position.x -= copysignf(adjustments[0], adjustments[2]);
			velocity.x = 0;
		}
		else
		{
			position.y -= copysignf(adjustments[1], adjustments[3]);
			velocity.y = 0;
		}
	}
}

Collider& Actor::getCollider() {
	return this->collider;
}

Vector2 Actor::getPosition() {
	return this->position;
}