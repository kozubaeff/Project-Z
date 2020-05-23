#include "subject.hpp"
#include <cassert>

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

Subject::Subject(int hitpoints)
        : mVelocity()
        , mHitpoints(hitpoints)
{
}

int Subject::getHitpoints() const
{
    return mHitpoints;
}

void Subject::repair(int points)
{
    assert(points > 0);
    mHitpoints += points;
}

void Subject::damage(int points)
{
    assert(points > 0);
    mHitpoints -= points;
}

void Subject::destroy()
{
    mHitpoints = 0;
}

bool Subject::isDestroyed() const
{
    return mHitpoints <= 0;
}
