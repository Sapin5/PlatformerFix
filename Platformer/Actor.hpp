#ifndef ACTOR_H
#define ACTOR_H
#include "BaseClass.hpp"
#include <string>


class Actor : public Base{
public:
	Vector2 position{ 0, 0 };
	int scale{ 5 };
	std::string tag{ "  " };

	Actor() = default;

	Actor(bool enableGravity ,Vector2 position, int scale, std::string tag) : Base( enableGravity) {
		this->position = position;
		this->scale = scale;
		this->tag = tag;
	}
	
	void drawActor();

	std::string getTag();

	void applyForce(Vector2 force);

	void update();
};

#endif // !ACTOR_H
