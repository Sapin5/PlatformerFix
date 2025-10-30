#ifndef ACTOR_H
#define ACTOR_H

#include "BaseClass.hpp"
#include "Collider.hpp"
#include <string>

class Actor : public Base{
protected:
	int scaleX;
	int scaleY;
	std::string tag{ "  " };
	Collider collider;

public:
	Vector2 position{};
	
	Actor() = default;

	Actor(bool enableGravity, Vector2 position, int scaleX, int scaleY, std::string tag, bool collisionEnabaled, bool debug) : Base( enableGravity ) {
		this->position = position;
		this->scaleX = scaleX;
		this->scaleY = scaleY;
		this->tag = tag;
		this->collider = Collider(position, {(float)scaleX, (float)scaleY}, collisionEnabaled, debug, this actor);
	}
	
	void drawActor();

	std::string getTag();

	void applyForce(Vector2 force);

	void update();
	void collisionCheck(Collider& other);
	Collider& getCollider();

	Vector2 getPosition();
};

#endif // !ACTOR_H
