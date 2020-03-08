#include <SFML/Graphics.hpp>
#include "object.h"
#include "objectui.h"

using namespace std;

ObjectUI::ObjectUI(unique_ptr<Object> rhs, sf::String file)
	: obj(move(rhs))
{}

uint8_t ObjectUI::getSpriteID() const {
	return spriteID;
}