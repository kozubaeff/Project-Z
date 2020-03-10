#include <SFML/Graphics.hpp>

#include "object.h"
#include "objectui.h"

ObjectUI::ObjectUI(std::unique_ptr<Object> rhs)
	: obj(move(rhs))
	, type(sprite_type)
{
	loadSprite();
}

void ObjectUI::loadSprite() {
	sf::Image image;
	switch (type) {
		case ObjectSprites::Tree:
			image.loadFromFile("images/tree.png");
		case ObjectSprites::Stone:
			image.loadFromFile("images/stone.png");
	}
	sf::Texture texture;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	switch (type) {
		case ObjectSprites::Tree:
			sprite.setTextureRect(sf::IntRect(0, 0, 50, 82));
		case ObjectSprites::Stone:
			sprite.setTextureRect(sf::IntRect(0, 0, 30, 30)); //TODO
	}
}

sf::Sprite ObjectUI::getSprite() const {
	return sprite;
}

void ObjectUI::drawSprite(sf::RenderWindow &window) {
	sprite.setPosition(obj->getX(), obj->getY());
	window.draw(sprite);
}