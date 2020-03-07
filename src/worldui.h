#include "world.h"

class WorldUI : public World {
public:
	void addSubject(std::unique_ptr<Subject> sbj);
	void addObject(std::unique_ptr<Object> obj);
};

