#include <iostream>
#include "raylib.h"
#include "game_m.hpp"
#include "MapParser.hpp"

int main()
{
     SetTargetFPS(100);
	 InitWindow(1600, 800, "Platformer");

     Platformer::GameManager Game;
     LoadMap();
     //drawMap();
     while (!WindowShouldClose()) {
         BeginDrawing();
         
         Game.updateGame();
         Game.drawScreen();
         
         Game.movePlayer();
         drawMap();
         EndDrawing();
     }
     CloseWindow();
     return 0;
}