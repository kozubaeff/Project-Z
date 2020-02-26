#include <memory>
#include <vector>

#include "object.h"
#include "subject.h"

class World {
public:
	std::vector<std::unique_ptr<Object>> objects;
	std::vector<std::unique_ptr<Subject>> subjects;

	void turn(void);
};

