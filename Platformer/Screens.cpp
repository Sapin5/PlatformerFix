#include "screen.hpp"
#include "Button.hpp"
#include <iostream>

namespace Platformer {
	Platformer::Button playButton(100, 100, 150, 150, BLUE, RED);
	Platformer::Button homeButton(100, 100, 150, 150, WHITE, BLACK);

	void Screen::setScreenSize(int screenX, int screenY) {
		screen_height = screenY;
		screen_width = screenX;
	}

	Screen::GameState Screen::getState() const {
		return currentState;
	}

	void Screen::update(char ch) {
		if (ch == 'p') {
			pause = true;
		}
	}

	void Screen::setScreen() {
		switch (currentState) {
		case  GameState::Home:
			if (playButton.drawButton()) currentState = GameState::Play;
			ClearBackground(RAYWHITE);
			break;
		case GameState::Play:
			ClearBackground(RAYWHITE);
			break;
		case GameState::Loss:
			if (homeButton.drawButton()) currentState = GameState::Home;
			ClearBackground(RED);
			break;
		case GameState::Win:
			if (homeButton.drawButton()) currentState = GameState::Home;
			ClearBackground(BLUE);
			break;
		}
	}

	void Screen::drawPlayer(player& player) {
		player.drawActor();
	}

	void Screen::drawActor(Actor& actor) {
		actor.drawActor();
	}

	void Screen::loadGameMap() {
		newMap.LoadMap();
	}

	void Screen::loadTileMap() {
		newMap.loadTileMap();
	}
}