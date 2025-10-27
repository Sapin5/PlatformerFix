#include <iostream>
#include "player.hpp"

void player::drawPlayer(){
	DrawRectangle(playerPos.x, playerPos.y, 10, 10, RED);
}

void player::movePlayer(char key) {
    
    if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
        playerPos.x += 0.05f;
    }

    if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
        playerPos.x -= 0.05f;
    }

    if (IsKeyDown(KEY_UP)) playerPos.y -= 0.05f;
    if (IsKeyDown(KEY_DOWN)) playerPos.y += 0.05f;
}