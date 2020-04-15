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



