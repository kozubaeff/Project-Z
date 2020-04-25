#ifndef WORLD_HPP
#define WORLD_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "object.hpp"
#include "Hero.hpp"
#include "CommandQueue.h"
#include "Command.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>

namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	const Hero* getHero() const;

    CommandQueue& getCommandQueue();


private:
	void loadTextures();
	void buildScene();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;
	Hero* mPlayer;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
};

#endif // WORLD_HPP