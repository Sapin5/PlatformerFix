#include "game_m.hpp"
#include "raymath.h"
#include <vector>
#include <iostream>
#include <array>

namespace Platformer {

	player playerOne(true, Vector2{ 100, 100 }, 40, 40, "player", "idk");
	std::vector<int> playerFrames{ 4, 6, 3, 6, 3, 4 };

	Actor floor(false, Vector2{ 100, 200 }, 40, 60, "floor", true, true);
	Actor floor2(false, Vector2{ 130, 220 }, 40, 60, "floor", true, true);

	/// <summary>
	/// Load all sprite sheets that the game will make use of
	/// </summary>
	void GameManager::loadAllSprites() {
		AnimationHandler* ptr = &playerAnimation;
		playerAnimation.loadSpriteSheet("Assets/Sprites/Characters/MinifolksHumans/Outline/MiniSwordMan.png", 6, playerFrames);
		playerOne.setAnimation(ptr);

		gameScreen.loadTileMap();
	}

	void GameManager::loadGameMap() {
		gameScreen.loadGameMap();
	}

	/// <summary>
	/// Draw player sprites during play state
	/// </summary>
	void GameManager::drawScreen(Camera2D& cam){
		key = Platformer::getKeyPressed();
		gameScreen.update(key);
		gameScreen.setScreen();

		if (gameScreen.getState() == Platformer::Screen::GameState::Play) {
			BeginMode2D(cam);
			gameScreen.drawPlayer(playerOne);

			gameScreen.drawActor(floor);
			gameScreen.drawActor(floor2);

			gameScreen.newMap.drawMapTiles();
			gameScreen.newMap.drawMap();
			EndMode2D();
		}
	}
	
	/// <summary>
	/// Pass keyboard input into player to move around
	/// </summary>
	void GameManager::movePlayer() {
		playerOne.movePlayer(key);
	}

	/// <summary>
	/// Update Players position
	/// Perform collision checks
	/// </summary>
	void GameManager::updateGame(Camera2D& cam) {

		if (gameScreen.getState() == Platformer::Screen::GameState::Play) {
			playerOne.update();

			cam.target = { (playerOne.getPosition().x - gameScreen.screen_width),
						   static_cast<float>(playerOne.getPosition().y - (gameScreen.screen_height / 1.5)) };

			playerOne.collisionCheck(floor.getCollider());
			playerOne.collisionCheck(floor2.getCollider());
		}
	}
}