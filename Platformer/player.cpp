#include <iostream>
#include "player.hpp"


void player::movePlayer(char key) {
    bool moveRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
    bool moveLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
    bool moveDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

    int newState = 0;

    if (collider.flags.bottom) {
        jump = true;
    }
    
    velocity.x = 0;

    std::cout << collider.flags.left;
    if (moveRight && !moveLeft) {
        velocity.x = 150;
        direction = 1;
        newState = 1;
        collider.flags.left = false;
    }

    if (moveLeft && !moveRight ) {
        velocity.x = -150;
        direction = -1;
        newState = 1;

    }

    if (moveDown) {
        velocity.y = 150;
        newState = 1;
    }

    if (IsKeyPressed(KEY_SPACE) && jump) {
        applyForce(Vector2{ 0, -200 });
        jump = false;
        collider.flags.bottom = false;

        if (onShake) {
            onShake(0.4f, 12.0f);
        }
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
        sprites->animate(state, position, 1.5f, Vector2 { 15.5, 28 }, direction);
    }
}