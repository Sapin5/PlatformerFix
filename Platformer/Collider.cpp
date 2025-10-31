#include "Collider.hpp"
#include <iostream>

void Collider::createCollider() {
    if (debug) {
        DrawRectangle(position.x, position.y, scale.x, scale.y, Color{ 255, 0, 0, 70 });
    }
}

void Collider::enableCollider(bool enabled) {
	this->enabled = enabled;
}

void Collider::updatePosition(Vector2& newPosition) {
	this->position = newPosition;
}

bool Collider::checkCollisions(Collider& other){
    if (!enabled || !other.enabled) return false;

    bool collisionX = position.x < other.position.x + other.scale.x &&
        position.x + scale.x > other.position.x;

    bool collisionY = position.y < other.position.y + other.scale.y &&
        position.y + scale.y > other.position.y;

    return (collisionX && collisionY);
}

std::vector<float> Collider::adjustPostion(Collider& other) {
    Vector2 thisHalf{ scale.x / 2, scale.y / 2 };
    Vector2 otherHalf{ other.scale.x / 2, other.scale.y / 2 };

    Vector2 thisCenter{ position.x + thisHalf.x, position.y + thisHalf.y };
    Vector2 otherCenter{ other.position.x + otherHalf.x, other.position.y + otherHalf.y };

    Vector2 delta{ otherCenter.x - thisCenter.x, otherCenter.y - thisCenter.y };

    Vector2 intersections{ thisHalf.x + otherHalf.x - fabs(delta.x),
                           thisHalf.y + otherHalf.y - fabs(delta.y) };


     return std::vector<float> { intersections.x, intersections.y, delta.x, delta.y};
    
}

Vector2 Collider::getPosition() const {
    return position;
}

Vector2 Collider::getScale() const {
    return scale;
}