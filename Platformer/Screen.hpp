#ifndef SCREENAMANGER_H
#define SCREENAMANGER_H
#include "raylib.h"
#include "player.hpp"

namespace Platformer {
	class screen {
	public:
		int screen_height{ 400 };
		int screen_width{ 400 };

		bool pause{ false };

		enum class GameState {Home, Win, Loss, Play};

		void setScreenSize(int screenX, int screenY);

		void update(char ch);

		void setScreen();

		GameState currentState{ GameState::Home };
	
		screen() = default;

		void drawPlayer(player& player);

		void drawActor(Actor& actor);

		GameState getState() const;
	private:
		
		static constexpr int totalGameSates{ 4 };
	};
}
#endif // !SCREENAMANGER
