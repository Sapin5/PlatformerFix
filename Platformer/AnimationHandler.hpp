#ifndef ANIMHANDLER_H
#define ANIMHANDLER_H
#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>

class AnimationHandler {
public:
	Texture2D playerSprites;
	std::vector<std::vector<int>> spriteSheetData;
	int currentFrame;
	float frameTime;
	float frameSpeed{ 0.1f };
	Vector2 playerSpriteSize;

	/// <summary>
	/// Loads sprite sheet based on file path.
	/// Sub divides sheet into rows and columns
	/// </summary>
	/// <param name="path">: Path to Sprite File</param>
	/// <param name="x">: Represents the total rows in the Sprite Sheet</param>
	/// <param name="y">: Set to the number of columns per row</param>
	void loadSpriteSheet(std::string path, int x, std::vector<int> y);

	/// <summary>
	/// Enabled animation to play based on current state for given actor
	/// </summary>
	/// <param name="state">: Used to access specific row along the sprite sheet</param>
	/// <param name="position">: Position at which the sprite will appear in the world </param>
	/// <param name="scale">: Scale up or down the sprite</param>
	/// <param name="adjustOrigin">: Readjust sprites position to recenter if needed</param>
	/// <param name="direction">: Allows sprite to be mirrored along the Y axis</param>
	void animate(int state, Vector2 position, float scale,
				 Vector2 adjustOrigin, int direction);

	/// <summary>
	/// Call when transitioning between states to avoid sprite not appearing properly
	/// </summary>
	void resetCurrentFrame();
};

#endif // !ANIMHANDLER_H
