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


void StateStack::applyPendingChanges()
{
    for(PendingChange change : mPendingList)
    {
        switch (change.action)
        {
            case Push:
                mStack.push_back(createState(change.stateID));
                break;

            case Pop:
                mStack.pop_back();
                break;

            case Clear:
                mStack.clear();
                break;
        }
    }
    mPendingList.clear();
}

void StateStack::pushState(States::ID stateID)
{
    mPendingList.emplace_back(Push, stateID);
}

void StateStack::popState()
{
    mPendingList.emplace_back(Pop);
}

void StateStack::clearStates()
{
    mPendingList.emplace_back(Clear);
}

bool StateStack::isEmpty() const
{
    return mStack.empty();
}


StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
        : action(action)
        , stateID(stateID)
{
}

StateStack::StateStack(State::Context context)
        : mStack()
        , mPendingList()
        , mContext(context)
        , mFactories()
{
}