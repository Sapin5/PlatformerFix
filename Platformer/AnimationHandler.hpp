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
	float frameSpeed{ 0.2f };
	Vector2 playerSpriteSize;

	void loadSpriteSheet(std::string path, int x, std::vector<int> y) {

		playerSprites = { LoadTexture(path.c_str()) };
		playerSpriteSize = { playerSprites.width / static_cast<float>(x), 
							 playerSprites.height / static_cast<float>(y.size()) };

		spriteSheetData.resize(x, std::vector<int>(2, 0));

		for (int i = 0; i < spriteSheetData.size(); i++) {
			spriteSheetData[i][0] = i;
		}

		for (int j = 0; j < std::min(spriteSheetData.size(), y.size()); j++) {
			spriteSheetData[j][1] = y[j];
		}
	}

	void animate(int state) {
		Rectangle sourceRec = { currentFrame * playerSpriteSize.x,
							state * playerSpriteSize.y,
							playerSpriteSize.x, playerSpriteSize.y };

		frameTime += GetFrameTime();
		if (frameTime >= frameSpeed) {
			currentFrame++;
			if (currentFrame >= spriteSheetData[state][1])
			{
				currentFrame = 0;
			}
			frameTime = 0.0f;
		}
		std::cout << spriteSheetData[state][0] << ", " << spriteSheetData[state][1] << "   ";
		std::cout << currentFrame * playerSpriteSize.x << ", " 
				  << state * playerSpriteSize.y << "\n";
		DrawTextureRec(playerSprites, sourceRec, Vector2{ 600, 200 }, WHITE);
	}

};

#endif // !ANIMHANDLER_H
