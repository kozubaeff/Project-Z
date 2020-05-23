#ifndef HERO_HPP
#define HERO_HPP

#include "subject.hpp"
#include "Command.h"
#include "ResourceIdentifiers.hpp"
#include "TextNode.h"

#include <SFML/Graphics/Sprite.hpp>


class Hero : public Subject
{
public:
	enum Type
	{
		Archer,
		Swordsman,
		Mage,
		TypeCount
	};


public:
	Hero(Type type, const TextureHolder& textures, const FontHolder& fonts);

    unsigned int getCategory() const;
    float getMaxSpeed() const;

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateTexts();
    void updateMovementPattern(sf::Time dt);

private:
	Type mType;
	sf::Sprite mSprite;

    float mTravelledDistance;
    std::size_t	mDirectionIndex;

    TextNode* mHealthDisplay;

};

#endif // HERO_HPP