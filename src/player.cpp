#include "player.h"
#include "CommandQueue.h"
#include "Hero.hpp"

struct Mover
{
    Mover(float vx, float vy)
            : velocity(vx, vy)
    {
    }
    void operator() (SceneNode& node, sf::Time) const
    {
        Hero& hero = static_cast<Hero&>(node);
        hero.setVelocity(velocity + hero.getVelocity());
    }
    sf::Vector2f velocity;
};

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {

}

void Player::handleRealtimeInput(CommandQueue &commands) {

}
