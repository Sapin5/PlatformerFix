#include "Actor.hpp"
#include <iostream>

void Actor::drawActor() {
	DrawRectangle(position.x, position.y, scale, scale, GREEN);
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
}