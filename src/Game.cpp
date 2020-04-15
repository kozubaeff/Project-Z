#include "Game.hpp"


#include <SFML/Window/Event.hpp>


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
const float mPlayerSpeed = 200.f;

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "MMORPG")
	, mWorld(mWindow)

{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);

		}

		render();
	}
}

void Game::processEvents()
{
    CommandQueue& commands = mWorld.getCommandQueue();

	sf::Event event;

	while (mWindow.pollEvent(event))
	{
	    mPlayer.handleEvent(event, commands);

	    if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Key::Escape)
	        mWindow.close();

	}
	mPlayer.handleRealtimeInput(commands);
}

void Game::update(sf::Time elapsedTime)
{
	mWorld.update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();

	mWindow.display();
}



