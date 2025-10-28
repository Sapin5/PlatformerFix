#include "Actor.hpp"
#include <iostream>

void Actor::drawActor() {
	DrawRectangle(static_cast<int>(position.x), static_cast<int>(position.y), scaleX, scaleY, GREEN);
	collider.createCollider();
}

std::string Actor::getTag() {
	return this->tag;
}

void Actor::applyForce(Vector2 force) {
	velocity.x += force.x;
	velocity.y += force.y;
}

void Actor::update() {
	applyGravity();
	position.x += velocity.x*GetFrameTime();
	position.y += velocity.y*GetFrameTime();

	collider.updatePosition(position);
}

void Actor::collisionCheck(Collider& other) {
	collider.checkCollisions(other);
}

Collider& Actor::getCollider() {
	return collider;
}