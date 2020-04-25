#ifndef THEGAME_GAMESERVER_H
#define THEGAME_GAMESERVER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

#include <vector>
#include <memory>
#include <map>

class GameServer
{
public:
    explicit GameServer(sf::Vector2f battlefieldSize);
    ~GameServer();

private:
    void handleIncomingPackets();
    void handleIncomingConnections();
    void handleDisconnections();
    void executionThread();
    void tick();

private:
    struct RemotePeer
    {
        RemotePeer();
        sf::TcpSocket socket;
        sf::Time lastPacketTime;
        std::vector<sf::Int32>	heroIdentifiers;
        bool ready;
        bool timedOut;
    };
    struct HeroInfo
    {
        sf::Vector2f position;
        sf::Int32 hitpoints;
        // healing per second, ammo etc.
        std::map<sf::Int32, bool> realtimeActions;
    };
    // Unique pointer to remote peers
    typedef std::unique_ptr<RemotePeer> PeerPtr;
private:
    sf::Thread mThread;
    sf::Clock mClock;
    sf::TcpListener	mListenerSocket;
    bool mListeningState;
    sf::Time mClientTimeoutTime;

    std::size_t	mMaxConnectedPlayers;
    std::size_t	mConnectedPlayers;

    float mWorldHeight;
    sf::FloatRect mBattleFieldRect;
    float mBattleFieldScrollSpeed;

    std::vector<PeerPtr> mPeers;
    std::size_t mHeroCount;
    std::map<sf::Int32, HeroInfo> mHeroInfo;

};



#endif //THEGAME_GAMESERVER_H
