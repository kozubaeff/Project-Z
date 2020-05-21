#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <math.h>

World::World(sf::RenderWindow& window)

	: mWindow(window)
	, mWorldView(sf::FloatRect (0.f, 0.f, mWindow.getSize().x, mWindow.getSize().y))
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mPlayer(nullptr)
	, mWorldBounds(0.f, 0.f, mWindow.getSize().x, mWindow.getSize().y) //change here
	, mCameraBounds(0.f, 0.f, mWindow.getSize().x, mWindow.getSize().y)
	, mSpawnPosition((mCameraBounds.left + mCameraBounds.width) / 2.f, (mCameraBounds.top + mCameraBounds.height )/ 2.f)

{
	loadTextures();
	buildScene();

	mMap = new Map(mWindow);
	mMap->load("../src/map.tmx", "../src/images/Slates.png");

	
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

    const float borderDist = 80.f;
    sf::Vector2f position = mPlayer->getPosition();
    velocity = mPlayer->getVelocity();
    float movePlayerOnX = velocity.x * dt.asSeconds();
    float movePlayerOnY = velocity.y * dt.asSeconds();

    if (position.x + movePlayerOnX > mCameraBounds.left + mCameraBounds.width * 3 / 4 ||
        position.x + movePlayerOnX < mCameraBounds.left + mCameraBounds.width / 4     ||
        position.y + movePlayerOnY > mCameraBounds.top + mCameraBounds.height * 3 / 4 ||
        position.y + movePlayerOnY < mCameraBounds.top + mCameraBounds.height / 4)
    {
        if(mCameraBounds.left + movePlayerOnX - borderDist>= 0 &&
        mCameraBounds.left + mCameraBounds.width + movePlayerOnX  + borderDist<= mWorldBounds.width
        && mCameraBounds.top + movePlayerOnY - borderDist >= 0 &&
           mCameraBounds.top + mCameraBounds.height + movePlayerOnY  + borderDist<= mWorldBounds.top + mWorldBounds.height) {

            mWorldView.move(velocity * dt.asSeconds());
            mWindow.setView(mWorldView);
            mCameraBounds.left += velocity.x * dt.asSeconds();
            mCameraBounds.top += velocity.y * dt.asSeconds();
        }


    }





    position.x = std::max(position.x,
                          borderDist);
    position.x = std::min(position.x, mWorldBounds.width - borderDist);
    position.y = std::max(position.y,
                             borderDist);
    position.y = std::min(position.y, mWorldBounds.height  - borderDist);



    mPlayer->setPosition(position);
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
	std::unique_ptr<Hero> leader(new Hero(Hero::Swordsman, mTextures));
	mPlayer = leader.get();
	mPlayer->setPosition(mSpawnPosition);
	mPlayer->setVelocity(0.f, 0.f);
	mSceneLayers[Air]->attachChild(std::move(leader));

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
