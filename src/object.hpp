#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "SceneNode.hpp"

#include <SFML/Graphics/Sprite.hpp>


class Object : public SceneNode
{
public:
	explicit Object(const sf::Texture& texture);
	Object(const sf::Texture& texture, const sf::IntRect& textureRect);


private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	sf::Sprite	mSprite;
};

#endif // OBJECT_HPP