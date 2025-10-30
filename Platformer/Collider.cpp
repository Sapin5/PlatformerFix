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

Collider::CollisionFlags Collider::betterCollisionCheck(Collider& other) {
    CollisionFlags flags;

    Vector2 thisHalf{ scale.x / 2, scale.y / 2 };
    Vector2 otherHalf{ other.scale.x / 2, other.scale.y / 2 };

    Vector2 thisCenter{ position.x + thisHalf.x, position.y + thisHalf.x };
    Vector2 otherCenter{ other.position.x + otherHalf.x, other.position.y + otherHalf.y };

    Vector2 delta{ otherCenter.x - thisCenter.x, otherCenter.y - thisCenter.y };

    Vector2 intersections{ thisHalf.x + otherHalf.x - fabs(delta.x),
                           thisHalf.y + otherHalf.y - fabs(delta.y) };

    std::cout << delta.y << " " << intersections.y << std::endl;

    if (intersections.x > 0 && intersections.y > 0) {
        if (delta.y > 0) {

            flags.bottom = true;
        }
        else {
            flags.top = true;
        }
        if (delta.x > 0) {
            flags.right = true;
        }
        else {
            flags.left = true;
        }
    }

    if (intersections.x < intersections.y)
    {
        this->position.x += copysignf(intersections.x, delta.x);
        actor.velocity.x = 0;
    }
    else
    {
        // cancel jump holding if vertical collision
       // this->cancelJump = (delta.y < 0);

        actor.position.y += copysignf(intersections.y, delta.y);
        actor.velocity.y = 0;
    }

    return flags;
}

Vector2 Collider::getPosition() const {
    return position;
}

Vector2 Collider::getScale() const {
    return scale;
}