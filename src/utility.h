#ifndef THEGAME_UTILITY_H
#define THEGAME_UTILITY_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <string>

namespace sf
{
    class Sprite;
    class Text;
}


void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);
float	toDegree(float radian);
float	toRadian(float degree);
std::string getKeyString(const sf::Keyboard::Key& key);
#endif //THEGAME_UTILITY_H