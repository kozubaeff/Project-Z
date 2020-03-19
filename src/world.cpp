#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
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
	// Scroll the world
	//mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	//TO-DO USE HANDLE INPUT
	//FOR NOW JUST GO SIDEWAYS
	// Move the player sidewards 
	sf::Vector2f position = mPlayer->getPosition();
	sf::Vector2f velocity = mPlayer->getVelocity();

	// If player touches borders, flip its X velocity
	/*
	if (position.x <= mWorldBounds.left + 150.f
		|| position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	{
		velocity.x = -velocity.x;
		mPlayer->setVelocity(velocity);
	}
	*/
	// Apply movements
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextures.load(Textures::Swordsman, "images/player.png");
	mTextures.load(Textures::Mage, "images/player.png");
	mTextures.load(Textures::Archer, "images/player.png");
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