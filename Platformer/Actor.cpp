#include "Actor.hpp"
#include <iostream>

void Actor::drawActor() {
	DrawRectangle(static_cast<int>(position.x), static_cast<int>(position.y), scaleX, scaleY, GREEN);
	this->collider.createCollider();
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
	auto flags{ collider.betterCollisionCheck(other) };

	if (flags.bottom) {
		this->velocity.y = 0;
		this->position.y = other.getPosition().y - scaleY;
		std::cout << "collision on bottom" << std::endl;
	}else if (flags.left) {
		position.x = other.getPosition().x + scaleX;
		std::cout << "collision on right" << std::endl;
	}else if (flags.right) {
		std::cout << "collision on right" << std::endl;
	}
}

Collider& Actor::getCollider() {
	return this->collider;
}

Vector2 Actor::getPosition() {
	return this->position;
}