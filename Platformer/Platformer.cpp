#include <iostream>
#include "raylib.h"
#include "game_m.hpp"

int main()
{
	 InitWindow(400, 400, "Platformer");

     Platformer::GameManager Game;
     
     while (!WindowShouldClose()) {
         BeginDrawing();
         Game.drawScreen();
         Game.movePlayer();
         EndDrawing();
     }
     CloseWindow();
     return 0;
}