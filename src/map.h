#ifndef MAP_H
#define MAP_H 

#include <iostream>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <tinyxml.h>

class Map {
public:
	Map(sf::RenderWindow& window) : mWindow(window) {};

	void load(std::string, std::string);
	void draw();

private:
	std::string mapName, imageName;

	int width, height, tileWidth, tileHeight;
	int firstTileID;

	std::unordered_map<int, sf::Sprite> sprites;
	std::vector<sf::Sprite> allSprites;

	sf::Texture tilesetImage;
	sf::RenderWindow& mWindow;

};

#endif