#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.hpp"

class player : public Actor {
public:

	std::string name{""};

	player() = default;

	player(bool enableGravity, Vector2 position, int scale, std::string tag, std::string name)
		: Actor(enableGravity, position, scale, tag) {
		this->name = name;
	}

	void movePlayer(char key);
};

#endif // !PLAYER_H
