#include "screen.hpp"
#include "Button.hpp"
#include <iostream>

namespace Platformer {

	void Screen::setScreenSize(int screenX, int screenY) {
		screen_height = screenY;
		screen_width = screenX;
	}

	Screen::GameState Screen::getState() const {
		return currentState;
	}

	void Screen::setState(GameState state)  {
		currentState = state;
	}

	void Screen::setScreen() {
		std::string play = "Play";

		Platformer::Button playButton(300, 100, GetScreenWidth() / 3, GetScreenHeight() / 3, BLUE, RED, play, 100);
		Platformer::Button homeButton(100, 100, 150, 150, WHITE, BLACK);
		switch (currentState) {
		case  GameState::Home:
			ClearBackground(RAYWHITE);
			if (playButton.drawButton()) currentState = GameState::Play;
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

	void Screen::loadGameMap(const std::string& filePath) {
		newMap.LoadMap(filePath);
		newMap.LoadCollisionMap("Assets/Maps/tilemap_packed_data.tsj");
	}

	void Screen::loadTileMap() {
		newMap.loadTileMap();
	}

	int Screen::getScreenWidth() {
		return screen_width;
	}

	int Screen::getScreenHeight() {
		return screen_height;
	}
}