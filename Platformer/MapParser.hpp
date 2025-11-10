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
public:
	/// <summary>
	/// Load map data from Tiled Json file
	/// </summary>
	void LoadMap(const std::string& filePath = " ") {
		std::ifstream f("Assets/Maps/Demomap.tmj");
		json data = json::parse(f);

		mapData = data.at("layers")[0].at("data").get<std::vector<int>>();
		mapSize = { data.at("height"), data.at("width") };
		tileShape = { data.at("tilewidth"), data.at("tileheight") };
	}

	/// <summary>
	/// Place temporary numbers in place future platform spots
	/// </summary>
	void drawMap() {
		for (int x = 0; x < mapData.size(); x++) {
			DrawText(TextFormat("%d", mapData[x]), (x % mapSize[1]) * 18, (x / mapSize[1]) * 18, 10, RED);
		}
	}

	/// <summary>
	/// Return the window size from Tiled json file
	/// </summary>
	/// <returns></returns>
	std::vector<int> getWindowSize() {
		return mapSize;
	}
};

#endif // !MAPPARSER_H