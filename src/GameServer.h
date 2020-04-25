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
    void inform(sf::TcpSocket& socket);
    sf::Time getCurrentTime() const;

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
    sf::Thread thread;
    sf::Clock clock;
    sf::TcpListener	listenerSocket;
    bool listeningState;
    sf::Time clientTimeoutTime;

    std::size_t	maxConnectedPlayers;
    std::size_t	connectedPlayers;

    float worldHeight;
    sf::FloatRect battleFieldRect;
    float battleFieldScrollSpeed;

    std::vector<PeerPtr> peers;
    //num of real peers plus one!
    //why ?  sf::TcpListener::accept() requires it
    std::size_t heroCount;
    std::map<sf::Int32, HeroInfo> heroInfo;

    sf::Int32	heroIdentifierCounter;
    // increases when new hero spawns , for different id's


};



#endif //THEGAME_GAMESERVER_H
