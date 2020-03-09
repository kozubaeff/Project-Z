#pragma once

#include <SFML/Graphics.hpp>

#include "subject.h"

class SubjectUI : public Subject {
public:
	SubjectUI(std::unique_ptr<Subject> sub);

	void loadSprite();

	sf::Sprite getSprite() const;

	void drawSprite(sf::RenderWindow &window);

private:
	std::unique_ptr<Subject> sub;
	SubjectSprites type;
	sf::Sprite sprite;
};
