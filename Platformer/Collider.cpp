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
    
    bool collisionX = static_cast<int>(position.x) < static_cast<int>(other.position.x) 
        + static_cast<int>(other.scale.x) && static_cast<int>(position.x) + 
        static_cast<int>(scale.x) > static_cast<int>(other.position.x);

    bool collisionY = static_cast<int>(position.y) < static_cast<int>(other.position.y)
        + static_cast<int>(other.scale.y) && static_cast<int>(position.y) +
        static_cast<int>(scale.y) > static_cast<int>(other.position.y);

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

    if (intersections.x > 0 && intersections.y > 0) {
        populateFlags(intersections, delta);
    }

    return std::vector<float> { intersections.x, intersections.y, delta.x, delta.y};
}


void Collider::populateFlags(Vector2 intersections, Vector2 delta) {
    
    // This does not work as intended since the goddamn flags wont clear

    // Determine the collision side based on smaller overlap
    if (intersections.x < intersections.y) {
        // Horizontal collision
        if (delta.x > 0) {
            // Other collider is to the right
            flags.right = true;
            flags.left = false;
            
        } else {
            // Other collider is to the left
            flags.left = true;
            flags.right = false;
        }
    }
    else {
        // Vertical collision
        if (delta.y > 0) {
            // Other collider is below
            flags.bottom = true;
        }
        else {
            // Other collider is above
            flags.top = true;
        }
    }
    
}


Vector2 Collider::getPosition() const {
    return position;
}

Vector2 Collider::getScale() const {
    return scale;
}