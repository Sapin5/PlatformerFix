#include <iostream>
#include "player.hpp"


void player::movePlayer(char key) {
    bool moveRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
    bool moveLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
    bool moveDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

    int newState = 0;

    if (collider.flags.bottom) {
        toggleGravity(false);
        jump = true;
    }
    
    velocity.x = 0;

    if (moveRight && !moveLeft) {
        toggleGravity(true);
        velocity.x = 150;
        direction = 1;
        newState = 1;
    }

    if (moveLeft && !moveRight ) {
        toggleGravity(true);
        velocity.x = -150;
        direction = -1;
        newState = 1;

    }

    if (moveDown && !collider.flags.bottom) {
        velocity.y += 20;
        newState = 2;
    }

    if (IsKeyPressed(KEY_SPACE) && jump) {
        applyForce(Vector2{ 0, -200 });
        toggleGravity(true);
        jump = false;
        collider.flags.bottom = false;

        if (onShake) {
            //onShake(0.4f, 12.0f);
        }
    }

    if (!jump) {
        newState = 2;
    }

    if (velocity.y > 50 || velocity.y < -50) {
        newState = 2;
    }

    if (newState != state) {
        state = newState;
        if (sprites) sprites->resetCurrentFrame();
    }
}

void player::resetPos() {
    position = initPos;
    toggleGravity(true);
    jump = false;
}


void player::drawActor() {
    this->collider.createCollider();

    bool grounded = collider.flags.bottom;

    if (sprites == nullptr) {
        DrawRectangle((int)position.x, (int)position.y, scaleX, scaleY, GREEN);
        return;
    }
    
    if (velocity.y < 50 && velocity.y > -50 && grounded) {
        if (velocity.x == 0) {
            sprites->animate(state, position, 1.5f, { 15.5,28 }, direction);
        }
        
        else {
            sprites->animate(state, position, 1.5f, { 15.5,28 }, direction);
        }
    }
    else {
        if (velocity.y < 0) {
            
            sprites->overrideCurrentFrame(state, position, 1.5f, { 15.5,28 }, direction, 0);
        }
        else {
            
            sprites->overrideCurrentFrame(state, position, 1.5f, { 15.5,28 }, direction, 1);
        }
    }
}
