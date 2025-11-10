#include <iostream>
#include "raylib.h"
#include "game_m.hpp"
#include "MapParser.hpp"

int main()
{
     MapParser newMap;
     newMap.LoadMap();
     std::vector<int> size = newMap.getWindowSize();
     SetTargetFPS(100);
	 InitWindow(size[0]*18, size[1]*18, "Platformer");

     Platformer::GameManager Game;

     Game.loadAllSprites();
     

     while (!WindowShouldClose()) {
         BeginDrawing();
         
         Game.updateGame();
         Game.drawScreen();
         Game.movePlayer();
         newMap.drawMap();
         
         EndDrawing();
     }
     CloseWindow();
     return 0;
}