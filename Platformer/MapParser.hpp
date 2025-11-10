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
public:
	/// <summary>
	/// Load map data from Tiled Json file
	/// </summary>
	void LoadMap(const std::string& filePath = " ") {
		std::ifstream f("Assets/Maps/Demomap2.tmj");
		json data = json::parse(f);

		mapData = data.at("layers")[0].at("data").get<std::vector<int>>();
		mapSize = { data.at("width"), data.at("height") };
		tileShape = { data.at("tilewidth"), data.at("tileheight") };

		tileSet = { LoadTexture("Assets/Maps/Demomap2.tmj") };
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