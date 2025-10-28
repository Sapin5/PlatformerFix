#include "screen.hpp"
#include "Button.hpp"
#include <iostream>

namespace Platformer {
	Platformer::Button playButton(100, 100, 150, 150, BLUE, RED);
	Platformer::Button homeButton(100, 100, 150, 150, WHITE, BLACK);

	void screen::setScreenSize(int screenX, int screenY) {
		screen_height = screenY;
		screen_width = screenX;
	}

	screen::GameState screen::getState() const {
		return currentState;
	}

	void screen::update(char ch) {
		if (ch == 'p') {
			pause = true;
		}
	}

	void screen::setScreen() {
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

	void screen::drawPlayer(player& player) {
		player.drawActor();
	}

	void screen::drawActor(Actor& actor) {
		actor.drawActor();
	}
}