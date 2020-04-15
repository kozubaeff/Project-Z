#include "World.hpp"
#include "map.h"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, mWorldView.getSize().y)
	, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, mPlayer(nullptr)
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	// Scroll the world when Player left the rectangle 320 on 240 px
	// Move the player
	sf::Vector2f position = mPlayer->getPosition();
	sf::Vector2f velocity = mPlayer->getVelocity();
	float movePlayerOnX = velocity.x * dt.asSeconds();
	float movePlayerOnY = velocity.y * dt.asSeconds();

	//Check player left the rectangle 320 on 240 px
	if (position.x + movePlayerOnX > mWorldBounds.left + mWorldBounds.width * 3 / 4 || 
		position.x + movePlayerOnX < mWorldBounds.left + mWorldBounds.width / 4     ||
		position.y + movePlayerOnY > mWorldBounds.top + mWorldBounds.height * 3 / 4 ||
		position.y + movePlayerOnY < mWorldBounds.top + mWorldBounds.height / 4) 
	{
		mWorldView.move(velocity * dt.asSeconds());
		mWindow.setView(mWorldView);
		mWorldBounds.left += velocity.x * dt.asSeconds();
		mWorldBounds.top += velocity.y * dt.asSeconds();
	}
    // Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
    while (!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);

	// Apply movements
	mSceneGraph.update(dt);
}

void World::draw()
{
	//Drar a primitive map
	Map map;
	map.load();
	map.draw_map(mWindow);

	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Swordsman, "player.png");
	mTextures.load(Textures::Mage, "player.png");
	mTextures.load(Textures::Archer, "player.png");
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
	std::unique_ptr<Hero> leader(new Hero(Hero::Swordsman, mTextures));
	mPlayer = leader.get();
	mPlayer->setPosition(mSpawnPosition);
	mPlayer->setVelocity(0.f, 0.f);
	mSceneLayers[Air]->attachChild(std::move(leader));

	// Add two mobs
	std::unique_ptr<Hero> leftMob(new Hero(Hero::Archer, mTextures));
	leftMob->setPosition(-80.f, 50.f);
	mPlayer->attachChild(std::move(leftMob));

	std::unique_ptr<Hero> rightMob(new Hero(Hero::Mage, mTextures));
	rightMob->setPosition(80.f, 50.f);
	mPlayer->attachChild(std::move(rightMob));
}

Hero* World::getHero() const {
	return mPlayer;
}

CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}
