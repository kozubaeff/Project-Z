#ifndef HERO_HPP
#define HERO_HPP

#include "subject.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/Graphics/Sprite.hpp>


class Hero : public Subject
{
public:
	enum Type
	{
		Archer,
		Swordsman,
		Mage,
	};


public:
	Hero(Type type, const TextureHolder& textures);
    unsigned int	getCategory() const;

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;

};

#endif // HERO_HPP