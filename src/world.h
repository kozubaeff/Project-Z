#include <memory>
#include <vector>

class Object {
};

class Subject {
};

class World {
public:
	std::vector<std::unique_ptr<Object>> objects;
	std::vector<std::unique_ptr<Subject>> subjects;

	void turn(void);
};

