#include "object.h"

using namespace std;

pair<int, int> Tree::getPosition() const {
	return make_pair(x, y);
}

int Tree::getHP() const {
	return hp;
}

