#include <SFML/Graphics.hpp>

#include "object.h"
#include "objectui.h"

using namespace std;

ObjectUI::ObjectUI(unique_ptr<Object> rhs)
	: obj(move(rhs))
	, type(sprite_type)
{
	loadSprite();
}

void ObjectUI::loadSprite() {
	sf::Image image;
	switch (type) {
		case Sprites::Tree:
			image.loadFromFile("images/tree.png");
		case Sprites::Stone:
			image.loadFromFile("images/stone.png");
	}
	sf::Texture texture;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	switch (type) {
		case Sprites::Tree:
			sprite.setTextureRect(sf::IntRect(0, 0, 50, 82));
		case Sprites::Stone:
			sprite.setTextureRect(sf::IntRect(0, 0, 30, 30)); //TODO
	}
}

sf::Sprite ObjectUI::getSprite() const {
	return sprite;
}

void ObjectUI::drawSprite(sf::RenderWindow &window) {
	window.draw(sprite);
}