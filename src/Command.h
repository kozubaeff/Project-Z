#ifndef THEGAME_COMMAND_H
#define THEGAME_COMMAND_H

#include <SFML/System/Time.hpp>
#include "Category.h"
#include <functional>

class SceneNode;
struct Command {
    Command();
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};

#endif //THEGAME_COMMAND_H
