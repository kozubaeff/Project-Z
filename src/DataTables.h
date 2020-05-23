#ifndef THEGAME_DATATABLES_H
#define THEGAME_DATATABLES_H

#include "ResourceIdentifiers.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <functional>

class Hero;

struct Direction
{
    Direction(float angle, float distance) : angle(angle), distance(distance) {}
    float angle;
    float distance;
};
struct HeroData
{
    int	hitpoints;
    float speed;
    Textures::ID texture;
    std::vector<Direction> directions;
};



std::vector<HeroData>	initializeHeroData();





#endif //THEGAME_DATATABLES_H
