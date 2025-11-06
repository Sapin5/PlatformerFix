#include "game_m.hpp"
#include "player.hpp"
#include <iostream>
#include <array>
#include "AnimationHandler.hpp"
#include <vector>

namespace Platformer {
	char key{ };
	
	player playerOne(true, Vector2{ 100, 100 }, 40, 40, "player", "idk");
	AnimationHandler playerAnimation;
	std::vector<int> playerFrames{ 4, 6, 3, 6, 3, 4 };

	Actor floor(false, Vector2{ 100, 200 }, 40, 60, "floor", true, true);
	Actor floor2(false, Vector2{ 130, 220 }, 40, 60, "floor", true, true);
	
	Platformer::screen gameScreen;


	void GameManager::loadAllSprites() {
		AnimationHandler* ptr = &playerAnimation;
		playerAnimation.loadSpriteSheet("Assets/Sprites/Characters/MinifolksHumans/Outline/MiniSwordMan.png", 6, playerFrames);
		playerOne.setAnimation(ptr);
	}

	//drawing
	void GameManager::drawScreen(){
		key = Platformer::getKeyPressed();
		gameScreen.update(key);
		gameScreen.setScreen();

		if (gameScreen.getState() == Platformer::screen::GameState::Play) {
			gameScreen.drawPlayer(playerOne);

			gameScreen.drawActor(floor);
			gameScreen.drawActor(floor2);
		}
	}
	//updating

	void GameManager::movePlayer() {
		playerOne.movePlayer(key);
	}

	void GameManager::updateGame() {
		if (gameScreen.getState() == Platformer::screen::GameState::Play) {
			playerOne.update();
			playerOne.collisionCheck(floor.getCollider());
			playerOne.collisionCheck(floor2.getCollider());
		}
	}
}