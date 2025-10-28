#include <iostream>
#include "raylib.h"
#include "game_m.hpp"

int main()
{
     SetTargetFPS(100);
	 InitWindow(800, 800, "Platformer");

     Platformer::GameManager Game;
     
     while (!WindowShouldClose()) {
         BeginDrawing();
         Game.updateGame();
         Game.drawScreen();
         
         Game.movePlayer();
         
         EndDrawing();
     }
     CloseWindow();
     return 0;
}