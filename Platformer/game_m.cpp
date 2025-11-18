#include "game_m.hpp"

namespace Platformer {

	player playerOne(true, Vector2{ 100, 500 }, 18, 18, "player", "idk");
	std::vector<int> playerFrames{ 4, 6, 3, 6, 3, 4 };


	GameManager::GameManager() {
		playerOne.onShake = [this](float duration, float magnitude) {
			this->triggerShake(duration, magnitude);
			};
	};

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

			for (int i = 0; i < tiles.size(); i++) {
				gameScreen.drawActor(tiles[i]);
			}

			gameScreen.newMap.drawMapTiles();
			gameScreen.newMap.drawMap();

			gameScreen.drawPlayer(playerOne);
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

			// Camera offset stays at the center of the screen
			cam.offset = { gameScreen.screen_width / 2.0f,
						   gameScreen.screen_height / 2.0f };
			cam.zoom = 1.5f;
			// Target position for the camera (player position with slight vertical offset)
			Vector2 targetPos = { playerOne.getPosition().x - 100,
								  playerOne.getPosition().y - 100};

			// Smoothly interpolate the camera's current target towards the player's position
			float cameraSpeed = 0.1f; // Adjust this value for more/less delay
			cam.target.x += (targetPos.x - cam.target.x) * cameraSpeed;
			cam.target.y += (targetPos.y - cam.target.y) * cameraSpeed;

			// Collision checks
			for (int i = 0; i < tiles.size(); i++) {
				playerOne.collisionCheck(tiles[i].getCollider());
			}

			if (shakeDuration > 0.0f) {
				float offsetX = (static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f) * shakeMagnitude;
				float offsetY = (static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f) * shakeMagnitude;
				cam.target.x += offsetX;
				cam.target.y += offsetY;

				shakeDuration -= GetFrameTime();
			}
		}
	}

	void GameManager::triggerShake(float duration, float magnitude) {
		shakeDuration = duration;
		shakeMagnitude = magnitude;
	}
}