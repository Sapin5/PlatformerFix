#include "raylib.h"
#include "game_m.hpp"

int main()
{
     Platformer::GameManager Game;
     Game.loadGameMap();
     Camera2D cam{ 0 };
     cam.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
     cam.zoom = 1.0f;
     std::vector<int> size{ Game.gameScreen.newMap.getWindowSize() };
     std::vector<int> screenSize { Game.gameScreen.newMap.getTileShape() };

     SetTargetFPS(60);

     InitWindow(size[0] * screenSize[0], size[1] * screenSize[1], "Platformer");

     Game.loadAllSprites();

     while (!WindowShouldClose()) {
         BeginDrawing();
         ClearBackground(RAYWHITE);
         Game.updateGame(cam);
         Game.drawScreen(cam);
         Game.movePlayer();

         EndDrawing();
     }
     CloseWindow();
     return 0;
}