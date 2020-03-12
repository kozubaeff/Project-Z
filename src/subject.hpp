#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "SceneNode.hpp"


class Subject : public SceneNode
{
public:
	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;


private:
	virtual void		updateCurrent(sf::Time dt);


private:
	sf::Vector2f		mVelocity;
};

#endif // SUBJECT_HPP