#ifndef THEGAME_APPLICATION_H
#define THEGAME_APPLICATION_H

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "player.h"
#include "stateStack.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
public :
    Application();
    void run();
private:
    void processInput();
    void update(sf::Time dt);
    void render();

    void updateStatistics(sf::Time dt);
    void registerStates();


private:
    static const sf::Time TimePerFrame;

    sf::RenderWindow mWindow;
    Player mPlayer;

    StateStack mStateStack;
};

#endif //THEGAME_APPLICATION_H
