#ifndef THEGAME_NETWORKPROTOCOL_H
#define THEGAME_NETWORKPROTOCOL_H

#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>

const unsigned short ServerPort = 5000;

namespace Server
{
    enum PacketType
    {
        BroadcastMessage,
        SpawnSelf,
        InitialState,
        PlayerEvent,
        PlayerRealtimeChange,
        PlayerConnect,
        PlayerDisconnect,
        UpdateClientState,
        GameEnded
    };
}

#endif //THEGAME_NETWORKPROTOCOL_H
