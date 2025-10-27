#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
class player {
public:
	void drawPlayer();
	void movePlayer(char key);

private:
	Vector2 playerPos{ 100, 100 };
	Vector2 playerVelocity{ 0, 0 };
};

#endif // !PLAYER_H
