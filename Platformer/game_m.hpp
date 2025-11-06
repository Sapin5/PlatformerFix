#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "raylib.h"
#include "screen.hpp"
#include "controller.hpp"

namespace Platformer {

	class GameManager {
	public:
		GameManager() = default;
		void loadAllSprites();
		void drawScreen();
		void movePlayer();
		void updateGame();
	};
	//drawing

	//updating
}
#endif // !GAMEMANAGEr
