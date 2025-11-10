#include "raylib.h"
#include "game_m.hpp"

int main()
{
     Platformer::GameManager Game;
     Game.loadGameMap();

     std::vector<int> size{ Game.gameScreen.newMap.getWindowSize() };
     std::vector<int> screenSize { Game.gameScreen.newMap.getTileShape() };

     SetTargetFPS(60);

     InitWindow(size[0] * screenSize[0], size[1] * screenSize[1], "Platformer");

     Game.loadAllSprites();

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