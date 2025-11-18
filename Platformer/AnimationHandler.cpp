#include "AnimationHandler.hpp"

void AnimationHandler::loadSpriteSheet(std::string path, int x, std::vector<int> y) {

	playerSprites = LoadTexture(path.c_str());
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

void AnimationHandler::animate(int state, Vector2 position, float scale,
	Vector2 adjustOrigin, int direction) {

	Rectangle sourceRec = { currentFrame * playerSpriteSize.x,
							state * playerSpriteSize.y,
							playerSpriteSize.x * direction,
							playerSpriteSize.y };


	Rectangle destRec = { position.x, position.y,
							playerSpriteSize.x * scale,
							playerSpriteSize.y * scale };


	Vector2 origin = { adjustOrigin.x, adjustOrigin.y };


	frameTime += GetFrameTime();
	if (frameTime >= frameSpeed) {
		currentFrame++;
		if (currentFrame >= spriteSheetData[state][1])
		{
			currentFrame = 0;
		}
		frameTime = 0.0f;
	}

	DrawTexturePro(playerSprites, sourceRec, destRec, origin, 0.0f, WHITE);
}

void AnimationHandler::overrideCurrentFrame(int state, Vector2 position, float scale,
	Vector2 adjustOrigin, int direction, int frame) {

	Rectangle sourceRec = { frame * playerSpriteSize.x,
							state * playerSpriteSize.y,
							playerSpriteSize.x * direction,
							playerSpriteSize.y };


	Rectangle destRec = { position.x, position.y,
							playerSpriteSize.x * scale,
							playerSpriteSize.y * scale };


	Vector2 origin = { adjustOrigin.x, adjustOrigin.y };

	DrawTexturePro(playerSprites, sourceRec, destRec, origin, 0.0f, WHITE);
}

void AnimationHandler::resetCurrentFrame() {
	currentFrame = 0;
	frameTime = 0.0f;
}
