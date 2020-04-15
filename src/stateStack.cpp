#include "stateStack.h"

#include <cassert>

State::Ptr StateStack::createState(States::ID stateID)
{
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());

    return found->second();
}

void StateStack::handleEvent(const sf::Event &event)
{
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); itr++)
    {
        if (!(*itr)->handleEvent(event))
            return;
    }
}

void StateStack::update(sf::Time dt)
{
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); itr++)
    {
        if (!(*itr)->update(dt))
            break;
    }

    applyPendingChanges();

}

void StateStack::draw()
{
    for (State::Ptr& state : mStack)
        state->draw();
}