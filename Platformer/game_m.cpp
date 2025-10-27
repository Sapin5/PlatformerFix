#include "game_m.hpp"
#include "player.hpp"
#include <iostream>

namespace Platformer {
	char key{ };
	player p1;
	Platformer::screen gameScreen(p1);
	
	
	//drawing
	void GameManager::drawScreen(){
		key = Platformer::getKeyPressed();
		gameScreen.update(key);
		gameScreen.setScreen();

	}
	//updating

	void GameManager::movePlayer() {
		p1.movePlayer(key);
	}
}