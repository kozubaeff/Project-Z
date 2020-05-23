#ifndef WORLD_HPP
#define WORLD_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "object.hpp"
#include "Hero.hpp"
#include "CommandQueue.h"
#include "Command.h"
#include "map.h"

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
	explicit World(sf::RenderWindow& window, FontHolder& fonts);
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

    struct SpawnPoint
    {
        SpawnPoint(Hero::Type type, float x, float y)
                : type(type)
                , x(x)
                , y(y)
        {
        }

        Hero::Type type;
        float x;
        float y;
    };

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
    FontHolder&	mFonts;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;
	Hero* mPlayer;

	sf::FloatRect mWorldBounds;
	sf::FloatRect mCameraBounds;
	sf::Vector2f mSpawnPosition;

	Map* mMap;

    std::vector<SpawnPoint>	mEnemySpawnPoints;
};

#endif // WORLD_HPP