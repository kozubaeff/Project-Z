#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "SceneNode.hpp"


class Subject : public SceneNode
{
public:
    explicit			Subject(int hitpoints);

	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;

    int	getHitpoints() const;
    void repair(int points);
    void damage(int points);
    void destroy();
    virtual bool isDestroyed() const;

protected:
	virtual void		updateCurrent(sf::Time dt);


private:
	sf::Vector2f mVelocity;
	int mHitpoints;
};

#endif // SUBJECT_HPP