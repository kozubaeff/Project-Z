#include <SFML/Graphics.hpp>

#include "subject.h"
#include "subjectui.h"

SubjectUI::SubjectUI(std::unique_ptr<Subject> rhs)
    : sub(move(rhs))
    , type(sprite_type)
{
    loadSprite();
	sprite.setPosition(rhs->getX, rhs->getY);
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
	sprite.setPosition(sub->getX(), sub->getY());
	window.draw(sprite);
}

void SubjectUI::update(float time, sf::RenderWindow &window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(-1.0 * time, 0);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(1.0 * time, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sprite.move(0, -1.0 * time);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sprite.move(0, 1.0 * time);
	}
	window.draw(sprite);
}