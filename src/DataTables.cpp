#include "DataTables.h"
#include "Hero.hpp"

using namespace std::placeholders;


std::vector<HeroData> initializeHeroData()
{
    std::vector<HeroData> data(Hero::TypeCount);

    data[Hero::Swordsman].hitpoints = 1500;
    data[Hero::Swordsman].speed = 100.f;
    data[Hero::Swordsman].texture = Textures::Swordsman;

    data[Hero::Mage].hitpoints = 800;
    data[Hero::Mage].speed = 50.f; // dist  = x*speed
    data[Hero::Mage].texture = Textures::Mage;
    data[Hero::Archer].directions.emplace_back(45, 50);
    data[Hero::Archer].directions.emplace_back(0, 50);
    data[Hero::Archer].directions.emplace_back(-45, 100);
    data[Hero::Archer].directions.emplace_back(0, 50);
    data[Hero::Archer].directions.emplace_back(45, 50);


    data[Hero::Archer].hitpoints = 1000;
    data[Hero::Archer].speed = 80.f;
    data[Hero::Archer].texture = Textures::Archer;
    data[Hero::Archer].directions.emplace_back(45, 80);
    data[Hero::Archer].directions.emplace_back(-45, 160);
    data[Hero::Archer].directions.emplace_back(45, 80);



    return data;
}