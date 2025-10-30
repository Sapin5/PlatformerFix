#ifndef COLLIDER_H
#define COLLIDER_H
#include "raylib.h"
#include <string>
#include <vector>
#include "Actor.hpp"

class Collider {
private:
	bool enabled{ true };
	Vector2 position{ 100.0f, 100.0f };
	Vector2 scale{ 100.0f, 100.0f };
	//std::vector<std::string> canCollide;
	bool debug{ false };

	bool collided{ false };

	Actor actor;

public:

	Collider() = default;

	//, std::vector<std::string> canCollide
	Collider(Vector2 position, Vector2 scale, bool enabled, bool debug, Actor actor) {
		this->position = position;
		this->scale = scale;
		this->enabled = enabled;
		//this->canCollide = canCollide;
		this->debug = debug;
		this->actor = actor;
	}

	struct CollisionFlags {
		bool top{ false };
		bool bottom{ false };
		bool left{ false };
		bool right{ false };
	};

	void createCollider();

	void enableCollider(bool enabled);

	void updatePosition(Vector2& newPosition);


	Collider::CollisionFlags betterCollisionCheck(Collider& other);

	Vector2 getPosition() const;
	Vector2 getScale() const;
};


#endif // !COLLIDER_H
