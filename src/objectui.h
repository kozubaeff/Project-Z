#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "object.h"

class ObjectUI : public Object {
public:
	ObjectUI(std::unique_ptr<Object> obj, sf::String file);

	uint8_t getSpriteID() const;

private:
	std::unique_ptr<Object> obj;
	uint8_t spriteID = 239;
};
