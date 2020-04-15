#ifndef THEGAME_COMMANDQUEUE_H
#define THEGAME_COMMANDQUEUE_H

#include "Command.h"
#include <queue>
class CommandQueue
{
public:
    void push(const Command& command);
    Command pop();
    bool isEmpty() const;

private:
    std::queue<Command> mQueue;
};
#endif //THEGAME_COMMANDQUEUE_H
