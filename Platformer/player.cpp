#include <iostream>
#include "player.hpp"


void player::movePlayer(char key) {
    
    if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
        position.x += 0.5f;
    }

    if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
        position.x -= 0.5f;
    }

    if (IsKeyDown(KEY_UP)) position.y -= 0.05f;
    if (IsKeyDown(KEY_DOWN)) position.y += 0.05f;
}