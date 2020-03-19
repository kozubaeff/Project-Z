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
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	mWorld.update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (isPressed) {
	if (key == sf::Keyboard::Key::Escape) {
		mWindow.close();
	}
	if (key == sf::Keyboard::Key::W) {
		mWorld.getHero()->setVelocity(0.f, -mPlayerSpeed);
	}
	if (key == sf::Keyboard::Key::A) {
		mWorld.getHero()->setVelocity(-mPlayerSpeed, 0.f);
	}
	if (key == sf::Keyboard::Key::S) {
		mWorld.getHero()->setVelocity(0.f, mPlayerSpeed);
	}
	if(key == sf::Keyboard::Key::D) {
		mWorld.getHero()->setVelocity(mPlayerSpeed, 0.f);
	}
	} else {
		mWorld.getHero()->setVelocity(0.f, 0.f);
	}
}
