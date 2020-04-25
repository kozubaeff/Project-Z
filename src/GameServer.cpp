#include "GameServer.h"
#include "Hero.hpp"
#include "NetworkProtocol.h"


#include <SFML/Network/Packet.hpp>
#include <memory>
#include <iostream>

GameServer::GameServer(sf::Vector2f battlefieldSize)
        : thread(&GameServer::executionThread, this)
        , listeningState(false)
        , clientTimeoutTime(sf::seconds(3.f))
        , maxConnectedPlayers(10)
        , connectedPlayers(0)
        , worldHeight(5000.f)
        , battleFieldRect(0.f, worldHeight - battlefieldSize.y, battlefieldSize.x, battlefieldSize.y)
        , battleFieldScrollSpeed(-50.f)
        , peers(1)
        , heroCount(0)
        , heroIdentifierCounter(1)
{
    listenerSocket.setBlocking(false);
    peers[0] = std::make_unique<RemotePeer>();
    thread.launch();
}

void GameServer::executionThread() {

}

void GameServer::handleIncomingPackets() {

}

void GameServer::handleIncomingConnections() {
    if (!listeningState)
        return;
    if (listenerSocket.accept(peers[connectedPlayers]->socket) == sf::TcpListener::Done)
    {
        heroInfo[heroIdentifierCounter].position = sf::Vector2f(battleFieldRect.width / 2, battleFieldRect.top + battleFieldRect.height / 2);
        heroInfo[heroIdentifierCounter].hitpoints = 100;

        sf::Packet packet;
        packet << static_cast<sf::Int32 >(Server::SpawnSelf);
        packet << heroIdentifierCounter;
        packet << heroInfo[heroIdentifierCounter].position.x;
        packet << heroInfo[heroIdentifierCounter].position.y;

        peers[connectedPlayers]->heroIdentifiers.push_back(heroIdentifierCounter);
        std::cout << "New player!" << '\n';
        inform(peers[connectedPlayers]->socket);

        heroIdentifierCounter++;

        peers[connectedPlayers]->socket.send(packet);
        peers[connectedPlayers]->ready = true;
        peers[connectedPlayers]->lastPacketTime = getCurrentTime();
        heroCount++;
        connectedPlayers++;


        //maxcount if clause
        peers.push_back(PeerPtr(new RemotePeer()));
    }
}

void GameServer::handleDisconnections() {

}

void GameServer::tick() {

}

void GameServer::inform(sf::TcpSocket &socket) {

}

sf::Time GameServer::getCurrentTime() const {
    return clock.getElapsedTime();
}


GameServer::RemotePeer::RemotePeer()
        : ready(false)
        , timedOut(false)
{
    socket.setBlocking(false);
}
