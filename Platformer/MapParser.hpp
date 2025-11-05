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

void LoadMap() {
	size = { data.at("height"), data.at("width") };
}

void drawMap(){
	
	for (int x = 0; x < mapData.size(); x++) {
		//std::cout << x;
		DrawText(TextFormat("%d", mapData[x]), (x % size[1]) * 18, (x/size[1]) * 18, 10, RED);
		//std::cout << (x % size[1]) *18 << " " << (x / size[1])*18 <<std::endl;

	}
}

#endif // !MAPPARSER_H