#include "Hero.hpp"
#include "DataTables.h"
#include "utility.h"
#include "CommandQueue.h"
#include "ResourceHolder.hpp"



#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


#include <cmath>

namespace
{
    const std::vector<HeroData> Table = initializeHeroData();
}

Hero::Hero(Type type, const TextureHolder& textures, const FontHolder& fonts)
	: Subject(Table[type].hitpoints)
	, mType(type)
	, mSprite(textures.get(Table[type].texture))
	, mTravelledDistance(0.f)
	, mDirectionIndex(0)
	, mHealthDisplay(nullptr)
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width, bounds.height);
	mSprite.setScale(2.0, 2.0);

    std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, ""));
    mHealthDisplay = healthDisplay.get();
    attachChild(std::move(healthDisplay));

    updateTexts();
}

void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
	//why not simple target.draw(mSprite) ?
	// see https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderStates.php#details
}

unsigned int Hero::getCategory() const{
    switch(mType) {
        case Swordsman:
            return Category::Hero;
        default:
            return Category::EnemyHero;
    }
}

void Hero::updateTexts()
{
    mHealthDisplay->setString(std::to_string(getHitpoints()) + " HP");
    mHealthDisplay->setPosition(0.f, 50.f);
    mHealthDisplay->setRotation(-getRotation());

}

void Hero::updateMovementPattern(sf::Time dt) {
    const std::vector<Direction>& directions  = Table[mType].directions;
    if(!directions.empty()) {
        // Moved long enough in current direction: Change direction
        if (mTravelledDistance > directions[mDirectionIndex].distance)
        {
            mDirectionIndex = (mDirectionIndex + 1) % directions.size();
            mTravelledDistance = 0.f;
        }

        // Compute velocity from direction
        float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
        float vx = getMaxSpeed() * std::cos(radians);
        float vy = getMaxSpeed() * std::sin(radians);

        setVelocity(vx, vy);

        mTravelledDistance += getMaxSpeed() * dt.asSeconds();
    }

}

float Hero::getMaxSpeed() const
{
    return Table[mType].speed;
}



