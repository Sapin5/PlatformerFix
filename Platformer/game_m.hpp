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
		bool pause{ false };

		GameManager();

		/// <summary>
		/// Load all sprites that will be used in the game
		/// </summary>
		void loadAllSprites();

		/// <summary>
		/// Draw all sprites on the screen
		/// </summary>
		/// <param name="cam">: Camera reference for camera to track player</param>
		void drawScreen(Camera2D& cam);

		/// <summary>
		/// Move player on key inputs
		/// </summary>
		void movePlayer();

		/// <summary>
		/// Update handles game state logic.
		/// Updates player logic (Gravity being applied).
		/// Performs collision checks.
		/// Handles Screen shake.
		/// </summary>
		/// <param name="cam"></param>
		void updateGame(Camera2D& cam);

		/// <summary>
		/// Loads the game map data (Sprite sheet and Json)
		/// </summary>
		/// <param name="filePath"></param>
		void loadGameMap(const std::string& filePath);

		/// <summary>
		/// Creates collisions in game world for player to walk around on
		/// </summary>
		void createMapCollisions();

		char key{ };

		Screen gameScreen;
		AnimationHandler playerAnimation;

		std::unordered_map<int, bool> idk;

		std::vector<Actor> tiles;

		float shakeDuration = 0.0f;
		float shakeMagnitude = 0.0f;

		/// <summary>
		///  Updates screenshake values to enable screen shake
		/// </summary>
		/// <param name="duration"></param>
		/// <param name="magnitude"></param>
		void triggerShake(float duration, float magnitude);
	};
}
#endif // !GAMEMANAGEr
