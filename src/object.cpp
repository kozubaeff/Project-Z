#include "object.hpp"

#include <SFML/Graphics/RenderTarget.hpp>


Object::Object(const sf::Texture& texture)
	: mSprite(texture)
{
}

Object::Object(const sf::Texture& texture, const sf::IntRect& textureRect)
	: mSprite(texture, textureRect)
{
}

void Object::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}