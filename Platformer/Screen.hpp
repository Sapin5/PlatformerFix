#ifndef SCREENAMANGER_H
#define SCREENAMANGER_H
#include "raylib.h"
#include "player.hpp"

namespace Platformer {
	class screen {
	public:
		int screen_height{ 100 };
		int screen_width{ 100 };

		enum class GameState {Home, Win, Loss, Play};

		void setScreenSize(int screenX, int screenY);

		void update(char ch);

		void setScreen();

		GameState currentState{ GameState::Home };
	
		screen() = default;

		screen(player& player):player(player) {}
	private:

		player& player;
		
		void drawPlayer();

		static constexpr int totalGameSates{ 4 };
	};
}
#endif // !SCREENAMANGER
