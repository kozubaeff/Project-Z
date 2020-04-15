#include "player.h"
#include "CommandQueue.h"
#include "Hero.hpp"

struct Mover
{
    Mover(float vx, float vy)
            : velocity(vx, vy)
    {
    }
    void operator() (Hero& hero, sf::Time) const
    {
        hero.setVelocity(velocity + hero.getVelocity());
    }
    sf::Vector2f velocity;
};

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {

}

void Player::handleRealtimeInput(CommandQueue &commands) {
    const float playerSpeed = 200.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Command moveLeft;
        moveLeft.category = Category::Hero;
        moveLeft.action = derivedAction<Hero>(
                Mover(-playerSpeed, 0.f));
        commands.push(moveLeft);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Command moveRight;
        moveRight.category = Category::Hero;
        moveRight.action = derivedAction<Hero>(
                Mover(playerSpeed, 0.f));
        commands.push( moveRight);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Command moveUp;
        moveUp.category = Category::Hero;
        moveUp.action = derivedAction<Hero>(
                Mover(0.f, -playerSpeed));
        commands.push( moveUp);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Command moveDown;
        moveDown.category = Category::Hero;
        moveDown.action = derivedAction<Hero>(
                Mover(0.f, playerSpeed));
        commands.push( moveDown);
    }

}
