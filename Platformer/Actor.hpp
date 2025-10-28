#ifndef ACTOR_H
#define ACTOR_H

#include "BaseClass.hpp"
#include "Collider.hpp"
#include <string>


class Actor : public Base{
protected:
	Vector2 position{ 0.0f, 0.0f };
	int scaleX{ 5 };
	int scaleY{ 5 };
	std::string tag{ "  " };
	Collider collider;

public:
	Actor() = default;

	Actor(bool enableGravity ,Vector2 position, int scaleX, int scaleY, std::string tag, bool collisionEnabaled, bool debug) : Base( enableGravity) {
		this->position = position;
		this->scaleX = scaleX;
		this->scaleY = scaleY;
		this->tag = tag;
		this->collider = Collider(position, {(float)scaleX, (float)scaleY}, collisionEnabaled, debug);
	}
	
	void drawActor();

	std::string getTag();

	void applyForce(Vector2 force);

	void update();
	void collisionCheck(Collider& other);
	Collider& getCollider();
};

#endif // !ACTOR_H
