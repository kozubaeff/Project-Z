#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

enum class Sprites {
    Tree,
    Stone
};

class Object {
public:
	Object(float _x, float _y, int h, bool damag, Sprites spr);
	virtual ~Object() = default;
	float getX() const;
	float getY() const;
	int getHP() const;
	Sprites sprite_type;
private:
	float x, y;
	int hp;
	bool damagable;
};