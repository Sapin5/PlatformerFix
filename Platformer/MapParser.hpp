#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
#include "raylib.h"

using json = nlohmann::json;

class MapParser {
private:
	std::vector<int> mapData;
	std::vector<int> mapSize;
	std::vector<int> tileShape;
	
	Texture2D tileSet;
	int tilesetColumns;
public:
	// Modify Loadmap to read the tsj file that contains collider bool, assign colliders accordingly?

	/// <summary>
	/// Load tilemap data from Json
	/// </summary>
	/// <param name="filePath"></param>
	void LoadMap(const std::string& filePath = " ") {
		std::ifstream f("Assets/Maps/Demomap3.tmj");
		json data = json::parse(f);

		mapData = data.at("layers")[0].at("data").get<std::vector<int>>();
		mapSize = { data.at("width"), data.at("height") };
		tileShape = { data.value("tilewidth", 18), data.value("tileheight", 18) };
	}


	/// <summary>
	/// Load the tilemap png from filepath
	/// </summary>
	/// <param name="filePath"></param>
	void loadTileMap(const std::string& filePath = " ") {
		tileSet = LoadTexture("Assets/Sprites/TileSet/tilemap_packed.png");
		tilesetColumns = tileSet.width / tileShape[0];
	}

	/// <summary>
	/// Draw the tiles on screen according to Json map
	/// </summary>
	void drawMapTiles() {

		for (int i = 0; i < mapData.size(); i++) {

			// Subtracts 1 from current position in mapData Array
			// Tiles actually start at index 0, but in the vector they are 1
			// this fixes that
			int tileIndex = mapData[i] - 1;
			if (tileIndex <= 0) continue;

			// Draw rectangle on tilemap to extract relevent tiles
			Rectangle sourceRect = {
				static_cast<float>((tileIndex % tilesetColumns) * tileShape[0]),
				static_cast<float>((tileIndex / tilesetColumns) * tileShape[1]),
				static_cast<float>(tileShape[0]), static_cast<float>(tileShape[1])
			};

			// Position which the tile is to be placed
			Vector2 destPos = {
				static_cast<float>((i % mapSize[0]) * tileShape[0]), 
					static_cast<float>((i / mapSize[0]) * tileShape[1])
			};

			// Draw tile on screen
			DrawTextureRec(tileSet, sourceRect, destPos, WHITE);
		}
	}


	/// <summary>
	/// Place temporary numbers in place future platform spots
	/// </summary>
	void drawMap() {
		for (int x = 0; x < mapData.size(); x++) {
			DrawText(TextFormat("%d", mapData[x]), (x % mapSize[0]) * tileShape[0], 
												   (x / mapSize[0]) * tileShape[1], 10, RED);
		}
	}

	/// <summary>
	/// Return the window size from Tiled json file
	/// </summary>
	/// <returns>
	/// vector { 0, 0 }
	/// </returns>
	std::vector<int> getWindowSize() {
		return mapSize;
	}

	std::vector<int> getTileShape() {
		return tileShape;
	}
};

#endif // !MAPPARSER_H