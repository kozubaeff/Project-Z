#include "player.h"
#include "CommandQueue.h"
#include "Hero.hpp"
#include <iostream>
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

Player::Player()
{
    mKeyBinding[sf::Keyboard::A] = MoveLeft;
    mKeyBinding[sf::Keyboard::D] = MoveRight;
    mKeyBinding[sf::Keyboard::W] = MoveUp;
    mKeyBinding[sf::Keyboard::S] = MoveDown;

    // Set initial action bindings
    initializeActions();

    // Assign all categories to player's hero
    for(auto& pair : mActionBinding) {
        pair.second.category = Category::Hero;
    }

}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    if (event.type == sf::Event::KeyPressed) {
        auto found = mKeyBinding.find(event.key.code);
        if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
            commands.push(mActionBinding[found->second]);
    }

}

void Player::initializeActions()
{
    const float playerSpeed = 200.f;

    mActionBinding[MoveLeft].action	 = derivedAction<Hero>(Mover(-playerSpeed, 0.f));
    mActionBinding[MoveRight].action = derivedAction<Hero>(Mover(playerSpeed, 0.f));
    mActionBinding[MoveUp].action    = derivedAction<Hero>(Mover(0.f, -playerSpeed));
    mActionBinding[MoveDown].action  = derivedAction<Hero>(Mover(0.f, playerSpeed));
}

void Player::handleRealtimeInput(CommandQueue &commands) {
    for(auto pair : mKeyBinding) {
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            commands.push(mActionBinding[pair.second]);
    }

}

bool Player::isRealtimeAction(Action action)
{
    switch (action)
    {
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
            return true;

        default:
            return false;
    }
}


void Player::assignKey(Action action, sf::Keyboard::Key key)
{
    // Remove all keys that already map to action
    for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
    {
        if (itr->second == action)
            mKeyBinding.erase(itr++);
        else
            ++itr;
    }

    // Insert new binding
    mKeyBinding[key] = action;
}


sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
    for(auto pair :  mKeyBinding)
    {
        if (pair.second == action)
            return pair.first;
    }

    return sf::Keyboard::Unknown;
}
