#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
#include "raylib.h"

using json = nlohmann::json;

struct TileInfo {
	float xPos;
	float yPos;
	int id;
};


class MapParser {
private:
	std::vector<int> mapData;
	std::vector<int> mapSize;
	std::vector<int> tileShape;

	std::unordered_map<int, bool> collisionTiles;
	std::vector <std::vector<float>> tilePosition;
	Texture2D tileSet;
	int tilesetColumns;
public:
	std::vector<TileInfo> tileCollison;

	std::vector<TileInfo> temp();

	// Modify Loadmap to read the tsj file that contains collider bool, assign colliders accordingly?

	/// <summary>
	/// Load tilemap data from Json
	/// </summary>
	/// <param name="filePath"></param>
	std::vector<int> LoadMap(const std::string& filePath);

	void fillStruct();
	std::unordered_map<int, bool> LoadCollisionMap(const std::string& filePath);


	/// <summary>
	/// Load the tilemap png from filepath
	/// </summary>
	/// <param name="filePath"></param>
	void loadTileMap(const std::string& filePath = " ");

	/// <summary>
	/// Draw the tiles on screen according to Json map
	/// </summary>
	void drawMapTiles();


	/// <summary>
	/// Place temporary numbers in place future platform spots
	/// </summary>
	void drawMap();

	/// <summary>
	/// Return the window size from Tiled json file
	/// </summary>
	/// <returns>
	/// vector { 0, 0 }
	/// </returns>
	std::vector<int> getWindowSize();
	

	/// <summary>
	/// Returns map data (Array of all tiles in game)
	/// </summary>
	/// <returns></returns>
	std::vector<int> getMapData();


	/// <summary>
	/// Returns shape of tiles (Pixel height and width)
	/// </summary>
	/// <returns></returns>
	std::vector<int> getTileShape();


	/// <summary>
	/// returns Umap of tiles that have their collision enabled
	/// </summary>
	/// <returns></returns>
	std::unordered_map<int, bool> getCollisionTiles();


	/// <summary>
	/// Returns the position of all tiles
	/// </summary>
	/// <returns></returns>
	std::vector< std::vector<float> > getTilePosition();
};

#endif // !MAPPARSER_H