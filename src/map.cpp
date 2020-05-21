#include "map.h"

void Map::load(std::string sourceMap, std::string pathTileset)
{
	mapName = sourceMap;
	imageName = pathTileset;

	//Load map file
	TiXmlDocument mapFile(mapName.c_str());
	if (!mapFile.LoadFile())
	{
		std::cout << "Loading level \"" << mapName << "\" failed." << std::endl;
		return;
	}

	TiXmlElement *map;
	map = mapFile.FirstChildElement("map");
 
	//Read the size of map and the size of tile
	width = atoi(map->Attribute("width"));
	height = atoi(map->Attribute("height")); 
	tileWidth = atoi(map->Attribute("tilewidth"));
	tileHeight = atoi(map->Attribute("tileheight"));

	//Load image
	sf::Image pngImage;
	pngImage.loadFromFile("images/Slates.png");
	tilesetImage.loadFromImage(pngImage);

	//To each ID tile add a range of tile in source image
	for (int y = 0; y < 24; y++) {
		for (int x = 0; x < 48; x++) {
			sf::Sprite sprite;
			sprite.setTexture(tilesetImage);
			sprite.setTextureRect(sf::IntRect(32 * x, 32 * y, 32, 32));
			sprites[y * 48 + x] = sprite;
		}
	}

	TiXmlElement *tilesetElement;
	tilesetElement = map->FirstChildElement("tileset");
	firstTileID = atoi(tilesetElement->Attribute("firstgid"));

	TiXmlElement *layer;
	layer = map->FirstChildElement("layer");
	while (layer) {
		TiXmlElement *layerDataElement;
		layerDataElement = layer->FirstChildElement("data");
		TiXmlElement *tileElement;
		tileElement = layerDataElement->FirstChildElement("tile");

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {

				int tileID = atoi(tileElement->Attribute("gid"));
				int needID = tileID - firstTileID;

				sf::Sprite sprite = sprites[needID];
				sprite.setPosition(32 * x, 32 * y);
				allSprites.push_back(sprite);

				tileElement = tileElement->NextSiblingElement("tile");
			}
		}
		layer = layer->NextSiblingElement("layer");
	}
}

void Map::draw() {
	for (int i = 0; i < allSprites.size(); i++) {
		mWindow.draw(allSprites[i]);
	}
}