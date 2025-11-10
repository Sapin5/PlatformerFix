#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "raylib.h"
#include "screen.hpp"
#include "player.hpp"
#include "AnimationHandler.hpp"
#include "controller.hpp"

namespace Platformer {

	class GameManager {
	public:
		GameManager() = default;

		void loadAllSprites();
		void drawScreen(Camera2D& cam);
		void movePlayer();
		void updateGame(Camera2D& cam);
		void loadGameMap();

		char key{ };

		Screen gameScreen;
		AnimationHandler playerAnimation;
	};
}
#endif // !GAMEMANAGEr
