#include <iostream>
#include "player.hpp"


void player::movePlayer(char key) {
    bool moveRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
    bool moveLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
    bool moveDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

    int newState = 0;

    if (moveRight && !moveLeft) {
        position.x += 0.5f;
        newState = 1;
        direction = 1;
    }

    if (moveLeft && !moveRight) {
        position.x -= 0.5f;
        newState = 1;
        direction = -1;
    }

    if (moveDown) {
        position.y += 0.5f;
        newState = 1;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        applyForce(Vector2{ 0, -200 });
        std::cout << "Jumped";
    }

    if (newState != state) {
        state = newState;
        if (sprites) sprites->resetCurrentFrame();
    }
}

void player::drawActor(){
    this->collider.createCollider();
    if (sprites == NULL) {
        DrawRectangle(static_cast<int>(position.x), static_cast<int>(position.y), scaleX, scaleY, GREEN);
    }
    else {
        sprites->animate(state, position, 2.5f, Vector2 { 20, 38 }, direction);
    }
}