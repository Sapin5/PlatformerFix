#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "raylib.h"
#include "screen.hpp"
#include "player.hpp"
#include "AnimationHandler.hpp"
#include "controller.hpp"
#include "raymath.h"
#include <vector>
#include <iostream>

namespace Platformer {

	class GameManager {
	public:
		GameManager() = default;

		void loadAllSprites();
		void drawScreen(Camera2D& cam);
		void movePlayer();
		void updateGame(Camera2D& cam);
		void loadGameMap(const std::string& filePath);
		void createMapCollisions();
		char key{ };

		Screen gameScreen;
		AnimationHandler playerAnimation;

		std::unordered_map<int, bool> idk;

		std::vector<Actor> tiles;
	};
}
#endif // !GAMEMANAGEr
