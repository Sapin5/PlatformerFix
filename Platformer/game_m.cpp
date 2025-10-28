#include "game_m.hpp"
#include "player.hpp"
#include <iostream>

namespace Platformer {
	char key{ };
	player playerOne(true, Vector2{ 100, 100 }, 40, 40, "player", "idk");

	Actor floor(false, Vector2{ 100, 200 }, 40, 20, "floor", true, true);
	Platformer::screen gameScreen;
	

	//drawing
	void GameManager::drawScreen(){
		key = Platformer::getKeyPressed();
		gameScreen.update(key);
		gameScreen.setScreen();

		if (gameScreen.getState() == Platformer::screen::GameState::Play) {
			gameScreen.drawPlayer(playerOne);
			gameScreen.drawActor(floor);
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
		}
	}
}