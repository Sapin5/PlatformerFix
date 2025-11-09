#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>
using json = nlohmann::json;

std::ifstream f("Assets/Maps/Demomap.tmj");
json data = json::parse(f);

std::vector<int> mapData = data.at("layers")[0].at("data");
std::vector<int> size;

/// <summary>
/// Load map data from Tiled Json file
/// </summary>
void LoadMap() {
	size = { data.at("height"), data.at("width") };
}

/// <summary>
/// Place temporary numbers in place future platform spots
/// </summary>
void drawMap(){
	for (int x = 0; x < mapData.size(); x++) {
		DrawText(TextFormat("%d", mapData[x]), (x % size[1]) * 18, (x/size[1]) * 18, 10, RED);
	}
}

#endif // !MAPPARSER_H