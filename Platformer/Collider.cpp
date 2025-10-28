#include "Collider.hpp"
#include <iostream>

void Collider::createCollider() {
    if (debug) {
        DrawRectangle(position.x, position.y, scale.x, scale.y, Color{ 255, 0, 0, 70 });
    }
}

bool Collider::checkCollisions(Collider& other) {
    
    if (!enabled || !other.enabled) return false;

    bool collisionX = position.x < other.position.x + other.scale.x &&
        position.x + scale.x > other.position.x;

    bool collisionY = position.y < other.position.y + other.scale.y &&
        position.y + scale.y > other.position.y;

    std::cout << (collisionX && collisionY);

    return collisionX && collisionY;
}

void Collider::enableCollider(bool enabled) {
	this->enabled = enabled;
}

void Collider::updatePosition(Vector2 newPosition) {
	this->position = newPosition;
    this->position.x -= 15;
    this->position.y -= 15;
}