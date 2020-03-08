#include <SFML/Graphics.hpp>

#include "object.h"
#include "objectui.h"

using namespace std;

ObjectUI::ObjectUI(unique_ptr<Object> rhs)
	: obj(move(rhs))
	, sprite(sprite_type)
{}

Sprites ObjectUI::getSprite() const {
	return sprite;
}

void ObjectUI::drawSprite(sf::RenderWindow&window) {
	if (sprite == Sprites::Tree) {
		sf::Image image;
		image.loadFromFile("images/tree");
		sf::Texture texture;
		texture.loadFromImage(image);
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 50, 82));
		window.draw(sprite);
	}
}