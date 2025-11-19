#include "raylib.h"
#include "game_m.hpp"

int main()
{
     Platformer::GameManager Game;
     Game.loadGameMap("Assets/Maps/GameMap.tmj");
     SetTargetFPS(60);
     
     /*
     * Could use this if smaller map. But like dont.
     * std::vector<int> size{ Game.gameScreen.newMap.getWindowSize() };
     * std::vector<int> screenSize{ Game.gameScreen.newMap.getTileShape() };
     * size[0] * screenSize[0], size[1] * screenSize[1]
     */
     Game.gameScreen.setScreenSize(1000, 600);

     InitWindow(Game.gameScreen.getScreenWidth(),
                Game.gameScreen.getScreenHeight(), "Platformer");

     Camera2D cam{ 0 };
     cam.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
     cam.zoom = 2.0f;


     Game.createButtons();
     Game.loadAllSprites();
     Game.createMapCollisions();

     while (!WindowShouldClose()) {
         BeginDrawing();
         ClearBackground(RAYWHITE);

         Game.movePlayer();
         Game.drawScreen(cam);  

         EndDrawing();
     }

     CloseWindow();
     return 0;
}