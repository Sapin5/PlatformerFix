#include "game_m.hpp"
namespace Platformer {

	player playerOne(true, Vector2{ 100, 100 }, 40, 40, "player", "idk");
	std::vector<int> playerFrames{ 4, 6, 3, 6, 3, 4 };

	void GameManager::createMapCollisions() {
		gameScreen.newMap.fillStruct();
		std::vector <TileInfo> temp = gameScreen.newMap.temp();
		std::vector<int> size{ gameScreen.newMap.getTileShape() };

		for (const auto& data: temp) {
			tiles.push_back(Actor(false, Vector2{ data.xPos, data.yPos }, 
									size[0], size[1], std::to_string(data.id), true, false));
		}
	}

	/// <summary>
	/// Load all sprite sheets that the game will make use of
	/// </summary>
	void GameManager::loadAllSprites() {
		AnimationHandler* ptr = &playerAnimation;
		playerAnimation.loadSpriteSheet("Assets/Sprites/Characters/MinifolksHumans/Outline/MiniSwordMan.png", 6, playerFrames);
		playerOne.setAnimation(ptr);
		gameScreen.loadTileMap();
	}

	/*
	* REMEMBER TO MODIFY THIS TO EXTRACT MAP DATA TO CREATE ACTORS LATER
	* PLEASE, IT TOOK YOU WAY TOO LONG TO THINK OF THIS
	*/
	void GameManager::loadGameMap(const std::string& filePath) {
		gameScreen.loadGameMap(filePath);
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

			for (int i = 0; i < tiles.size(); i++) {
				gameScreen.drawActor(tiles[i]);
			}

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

			for (int i = 0; i < tiles.size(); i++) {
				playerOne.collisionCheck(tiles[i].getCollider());
			}
		}
	}
}