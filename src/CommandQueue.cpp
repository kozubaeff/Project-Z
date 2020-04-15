#include "CommandQueue.h"

bool CommandQueue::isEmpty() const
{
    return mQueue.empty();
}

void CommandQueue::push(const Command &command) {
    mQueue.push(command);
}

Command CommandQueue::pop() {
    Command command = mQueue.front();
    mQueue.pop();
    return command;
}
