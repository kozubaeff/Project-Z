#include "objectui.h"

using namespace std;

ObjectUI::ObjectUI(unique_ptr<Object> rhs)
	: obj(move(rhs))
{}

uint8_t ObjectUI::getSpriteID() const {
	return spriteID;
}

float ObjectUI::getX() const {
	return obj->getX();
}

float ObjectUI::getY() const {
	return obj->getY();
}

int ObjectUI::getHP() const {
	return obj->getHP();
}
