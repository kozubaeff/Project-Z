#include "application.h"
#include "state.h"
#include "stateIdentifiers.h"
#include "gameState.h"
#include "titleState.h"
#include "menuState.h"
#include "pauseState.h"
#include "loadingState.h"
#include "settingState.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

void Application::registerStates()
{

    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<LoadingState>(States::Loading);
    mStateStack.registerState<SettingsState>(States::Settings);
}

Application::Application()
        : mWindow(sf::VideoMode(640, 480), "Project Z", sf::Style::Close)
        , mTextures()
        , mFonts()
        , mPlayer()
        , mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
        , mStatisticsText()
        , mStatisticsUpdateTime()
        , mStatisticsNumFrames(0)
{
    mWindow.setKeyRepeatEnabled(false);

    mFonts.load(Fonts::Main, "../src/fonts/Sansation.ttf");

    mTextures.load(Textures::TitleScreen,		"../src/images/titleScreen.png");
    mTextures.load(Textures::ButtonNormal, "../src/images/ButtonNormal.png");
    mTextures.load(Textures::ButtonPressed, "../src/images/ButtonPressed.png");
    mTextures.load(Textures::ButtonSelected, "../src/images/ButtonSelected.png");

    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    mStateStack.pushState(States::Title);
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
        updateStatistics(dt);
        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);

        if (event.type == sf::Event::Closed )
            mWindow.close();
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();

    mStateStack.draw();

    mWindow.draw(mStatisticsText);
    mWindow.display();
}


void Application::updateStatistics(sf::Time dt)
{
    mStatisticsUpdateTime += dt;
    mStatisticsNumFrames += 1;
    if (mStatisticsUpdateTime >= sf::seconds(1.0f))
    {
        mStatisticsText.setString("FPS: " + std::to_string(mStatisticsNumFrames));

        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

