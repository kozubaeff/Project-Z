#include "Hero.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(Hero::Type type)
{
	switch (type)
	{
	case Hero::Swordsman:
		return Textures::Swordsman;

	case Hero::Archer:
		return Textures::Archer;
	}
	return Textures::Mage;
}

Hero::Hero(Type type, const TextureHolder& textures)
	: mType(type)
	, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
	//why not simple target.draw(mSprite) ?
	// see https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderStates.php#details
}
