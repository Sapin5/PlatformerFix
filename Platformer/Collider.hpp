#ifndef COLLIDER_H
#define COLLIDER_H
#include "raylib.h"
#include <string>
#include <vector>


class Collider {
private:
	bool enabled{ true };
	Vector2 position{ 100.0f, 100.0f };
	Vector2 scale{ 100.0f, 100.0f };
	//std::vector<std::string> canCollide;
	bool debug{ false };
public:

	Collider() = default;

	//, std::vector<std::string> canCollide
	Collider(Vector2 position, Vector2 scale, bool enabled, bool debug) {
		this->position = position;
		this->scale = scale;
		this->enabled = enabled;
		//this->canCollide = canCollide;
		this->debug = debug;

		this->scale.x += 30;
		this->scale.y += 30;

		this->position.x -= 15;
		this->position.y -= 15;
	}
	bool checkCollisions(Collider& collider);

	void createCollider();

	void enableCollider(bool enabled);

	void updatePosition(Vector2 newPosition);
};


#endif // !COLLIDER_H
