#ifndef THEGAME_PLAYER_H
#define THEGAME_PLAYER_H

#include "Command.h"

#include <SFML/Window/Event.hpp>

class CommandQueue;

class Player
{
public:
    void handleEvent(const sf::Event& event,
                            CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};
#endif //THEGAME_PLAYER_H
