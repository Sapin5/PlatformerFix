#ifndef SCREENAMANGER_H
#define SCREENAMANGER_H
#include "raylib.h"
#include "player.hpp"
#include "MapParser.hpp"

namespace Platformer {
	class Screen {
	public:
		int screen_height{ 400 };
		int screen_width{ 400 };
		bool pause{ false };
		MapParser newMap;

		enum class GameState {Home, Win, Loss, Play};
		GameState currentState{ GameState::Home };
		GameState getState() const;

		void loadGameMap(const std::string& filePath);
		void loadTileMap();
		void setScreenSize(int screenX, int screenY);
		void update(char ch);
		void setScreen();
		void drawPlayer(player& player);
		void drawActor(Actor& actor);
		
		
		Screen() = default;
	private:
		
		static constexpr int totalGameSates{ 4 };
	};
}
#endif // !SCREENAMANGER
