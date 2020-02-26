#include <utility>

class Object {
public:
	virtual ~Object() = default;
	virtual std::pair<int, int> getPosition() const = 0;
	virtual int getHP() const = 0;
};

class Tree : public Object {
public:
	std::pair<int, int> getPosition() const override;
	int getHP() const override;

private:
	int hp = 10;
	int x = 239;
	int y = 17;
};

