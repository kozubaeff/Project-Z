#pragma once

#include <SFML/Graphics.hpp>

enum class SubjectSprites {
	Hero
};

class Subject {
public:
	Subject();
	Subject(float _x, float _y, int h, SubjectSprites type);
	float getX();
	float getY();
	int getHP();
	virtual ~Subject() = default;
protected:
	SubjectSprites sprite_type;
private:
	float x, y;
	int hp;
};

