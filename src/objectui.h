#pragma once

#include <memory>
#include "object.h"

class ObjectUI : public Object {
public:
	ObjectUI(std::unique_ptr<Object> obj);

	uint8_t getSpriteID() const;

	float getX() const override;
	float getY() const override;
	int getHP() const override;

private:
	std::unique_ptr<Object> obj;
	uint8_t spriteID = 239;
};
