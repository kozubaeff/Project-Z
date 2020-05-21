#ifndef THEGAME_LOADINGSTATE_H
#define THEGAME_LOADINGSTATE_H

#include "state.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "parallelTask.h"


class LoadingState : public State
{
public:
    LoadingState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    void setCompletion(float percent);

private:
    sf::Text mLoadingText;
    sf::RectangleShape mProgressBarBackground;
    sf::RectangleShape mProgressBar;

    ParallelTask mLoadingTask;
};


#endif //THEGAME_LOADINGSTATE_H
