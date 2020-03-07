#include <utility>

class Object {
public:
	virtual ~Object() = default;
	virtual float getX() const;
	virtual float getY() const;
	virtual int getHP() const = 0;
private:
	float x, y;
	int hp;
};

class Tree : public Object {
public:
	float getX() const override;
	float getY() const override;
	int getHP() const override;
private:
	int x = 239;
	int y = 17;
	int hp = 10;
};

