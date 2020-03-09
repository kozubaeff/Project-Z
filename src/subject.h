#pragma once

class Subject {
public:
	Subject(float _x, float _y, int h);
	float getX();
	float getY();
	int getHP();
	virtual ~Subject() = default;
private:
	float x, y;
	int hp;
};

