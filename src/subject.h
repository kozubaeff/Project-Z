#pragma once

class Subject {
public:
	Subject(float x, float y, int hp);
	virtual ~Subject() = default;
private:
	float x, y;
	int hp;
};

