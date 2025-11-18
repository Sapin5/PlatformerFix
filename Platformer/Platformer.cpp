#include "raylib.h"
#include "game_m.hpp"

int main()
{
     Platformer::GameManager Game;
     Game.loadGameMap("Assets/Maps/GameMap.tmj");

     Camera2D cam{ 0 };
     cam.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
     cam.zoom = 1.0f;
     std::vector<int> size{ Game.gameScreen.newMap.getWindowSize() };
     std::vector<int> screenSize { Game.gameScreen.newMap.getTileShape() };

     SetTargetFPS(60);
     
     //size[0] * screenSize[0], size[1] * screenSize[1]
     InitWindow(1000, 600, "Platformer");

     Game.loadAllSprites();
     Game.createMapCollisions();

     while (!WindowShouldClose()) {
         BeginDrawing();
         ClearBackground(RAYWHITE);

         Game.movePlayer();
         Game.updateGame(cam);
         Game.drawScreen(cam);  

         EndDrawing();
     }

     CloseWindow();
     return 0;
}