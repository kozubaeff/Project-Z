#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "object.h"

class ObjectUI : public Object {
public:
	ObjectUI(std::unique_ptr<Object> obj);

	void loadSprite();

	sf::Sprite getSprite() const;

	void drawSprite(sf::RenderWindow &window);

private:
	std::unique_ptr<Object> obj;
	Sprites type;
	sf::Sprite sprite;
};
