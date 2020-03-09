#include <SFML/Graphics.hpp>

#include "subject.h"
#include "subjectui.h"

SubjectUI::SubjectUI(std::unique_ptr<Subject> rhs)
    : sub(move(rhs))
    , type(sprite_type)
{
    loadSprite();
}

void SubjectUI::loadSprite() {
	sf::Image image;
	switch (type) {
		case SubjectSprites::Hero:
			image.loadFromFile("images/hero.png"); //TODO
	}
	sf::Texture texture;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	switch (type) {
		case SubjectSprites::Hero:
			sprite.setTextureRect(sf::IntRect(0, 0, 50, 82)); //TODO
	}
}

sf::Sprite SubjectUI::getSprite() const {
	return sprite;
}

void SubjectUI::drawSprite(sf::RenderWindow &window) {
	window.draw(sprite);
}
