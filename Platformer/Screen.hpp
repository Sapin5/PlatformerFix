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


		/// <summary>
		/// Loads the Game Map from filepath
		/// </summary>
		/// <param name="filePath"></param>
		void loadGameMap(const std::string& filePath);


		/// <summary>
		/// Loads tile map sprite pack
		/// </summary>
		void loadTileMap();


		/// <summary>
		/// Returns a desired screen size. Unused
		/// </summary>
		/// <param name="screenX"></param>
		/// <param name="screenY"></param>
		void setScreenSize(int screenX, int screenY);

		/// <summary>
		/// Checks for key input during gameplay that is not movement related
		/// </summary>
		/// <param name="ch"></param>
		void update(char ch);

		/// <summary>
		/// Changes screen based on game state
		/// </summary>
		void setScreen();


		/// <summary>
		/// Draws player
		/// </summary>
		/// <param name="player"></param>
		void drawPlayer(player& player);

		/// <summary>
		/// Draws actor
		/// </summary>
		/// <param name="actor"></param>
		void drawActor(Actor& actor);
		
		Screen() = default;
	private:
		
		static constexpr int totalGameSates{ 4 };
	};
}
#endif // !SCREENAMANGER
