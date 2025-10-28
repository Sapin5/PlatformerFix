#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Actor.hpp"

class player : public Actor {
public:
	void drawPlayer();
	void movePlayer(char key);

private:
	Vector2 playerPos{ 100.0, 100.0 };
	Vector2 playerVelocity{ 0, 0 };
};

#endif // !PLAYER_H
