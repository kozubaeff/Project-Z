#include "subject.hpp"


void Subject::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Subject::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Subject::getVelocity() const
{
	return mVelocity;
}

void Subject::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}