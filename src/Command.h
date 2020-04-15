#ifndef THEGAME_COMMAND_H
#define THEGAME_COMMAND_H

#include <SFML/System/Time.hpp>
class SceneNode;
struct Command {
    std::function<void(SceneNode&, sf::Time)> action;
};

#endif //THEGAME_COMMAND_H
