#include "application.h"
#include "state.h"
#include "stateIdentifiers.h"
#include "gameState.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

void Application::registerStates()
{
    // To-Do Other States
    mStateStack.registerState<GameState>(States::Game);
}

Application::Application()
        : mWindow(sf::VideoMode(640, 480), "States", sf::Style::Close)
        , mTextures()
        , mPlayer()
        , mStateStack(State::Context(mWindow, mTextures, mPlayer))
{
    mWindow.setKeyRepeatEnabled(false);

    registerStates();
    mStateStack.pushState(States::Game);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);

            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }
        render();
    }
}



