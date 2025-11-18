#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.hpp"

class player : public Actor {
public:
	int state{ 0 };
	int direction{ 1 };
	std::string name{""};
	bool jump{ false };

	player() = default;


	player(bool enableGravity, Vector2 position, int scaleX, int scaleY, std::string tag, std::string name)
		: Actor(enableGravity, position, scaleX, scaleY, tag, true, true) {
		this->name = name;
	}


	/// <summary>
	/// Move the player based on key pressed
	/// </summary>
	/// <param name="key"></param>
	void movePlayer(char key);

	/// <summary>
	/// overrides draw actor present in parent class
	/// Allows for sprites to be drawn
	/// </summary>
	void drawActor() override;

	
};

#endif // !PLAYER_H
