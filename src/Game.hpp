#ifndef GAME_HPP
#define GAME_HPP

#include "World.hpp"
#include "player.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Game : private sf::NonCopyable
{
public:
	Game();
	void run();


private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;
	World mWorld;
    Player	mPlayer;

};

#endif // GAME_HPP