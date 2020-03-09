#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectSprites {
    Tree,
    Stone
};

class Object {
public:
	Object();
	Object(float _x, float _y, int h, bool damag, ObjectSprites spr);
	virtual ~Object() = default;
	float getX() const;
	float getY() const;
	int getHP() const;
protected:
	ObjectSprites sprite_type;
private:
	float x, y;
	int hp;
	bool damagable;
};