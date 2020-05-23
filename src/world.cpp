#include "World.hpp"
#include "TextNode.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>


World::World(sf::RenderWindow& window, FontHolder& fonts)
	: mWindow(window)
	, mWorldView(sf::FloatRect (0.f, 0.f, mWindow.getSize().x, mWindow.getSize().y))
	, mTextures()
	, mFonts(fonts)
	, mSceneGraph()
	, mSceneLayers()
	, mPlayer(nullptr)
	, mWorldBounds(0.f, 0.f, 1000, 1000) //change here
	, mSpawnPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f)

{
    mWindow.setView(mWorldView);
	loadTextures();
	buildScene();


	
	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{

    // Forward commands to scene graph
    mPlayer->setVelocity(0.f, 0.f);
    while (!mCommandQueue.isEmpty()) {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }


    sf::Vector2f velocity = mPlayer->getVelocity();
    if (velocity.x != 0.f && velocity.y != 0.f) {
        mPlayer->setVelocity(velocity / std::sqrt(2.f));
    }

    const float borderDistX = mWindow.getSize().x / 2.f + 50;
    const float borderDistY = mWindow.getSize().y / 2.f + 50;
    sf::Vector2f position = mPlayer->getPosition();


    position.x = std::max(position.x, borderDistX);
    position.x = std::min(position.x, mWorldBounds.width - borderDistX);
    position.y = std::max(position.y, borderDistY);
    position.y = std::min(position.y, mWorldBounds.height - borderDistY);



    mPlayer->setPosition(position);

    sf::Vector2f movement = mPlayer->getPosition() - mWorldView.getCenter();
    mWorldView.move(movement * dt.asSeconds());
    mWindow.setView(mWorldView);
    // Apply movements
	mSceneGraph.update(dt);



}

void World::draw()
{
	//Draw a primitive map
	mMap->draw();

	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Swordsman, "../src/images/player.png");
	mTextures.load(Textures::Mage, "../src/images/player.png");
	mTextures.load(Textures::Archer, "../src/images/player.png");
}

void World::buildScene()
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	

	// Add player
	std::unique_ptr<Hero> leader(new Hero(Hero::Swordsman, mTextures, mFonts));
	mPlayer = leader.get();
	mPlayer->setPosition(mSpawnPosition);
	mPlayer->setVelocity(0.f, 0.f);
	mSceneLayers[Air]->attachChild(std::move(leader));


    mMap = new Map(mWindow);
    mMap->load("../src/map.tmx", "../src/images/Slates.png");
	// Add two mobs
	// std::unique_ptr<Hero> leftMob(new Hero(Hero::Archer, mTextures));
	// leftMob->setPosition(-80.f, 50.f);
	// mPlayer->attachChild(std::move(leftMob));

	// std::unique_ptr<Hero> rightMob(new Hero(Hero::Mage, mTextures));
	// rightMob->setPosition(80.f, 50.f);
	// mPlayer->attachChild(std::move(rightMob));
}

const Hero* World::getHero() const {
	return mPlayer;
}

CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}
