#ifndef THEGAME_GAMESTATE_H
#define THEGAME_GAMESTATE_H

#include "state.h"
#include "World.hpp"
#include "player.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class GameState : public State
{
public:

    GameState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

private:
    World mWorld;
    Player&	mPlayer;
};
#endif //THEGAME_GAMESTATE_H
