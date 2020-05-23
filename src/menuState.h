#ifndef THEGAME_MENUSTATE_H
#define THEGAME_MENUSTATE_H

#include "state.h"
#include "container.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);


private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
    bool firstEvent; // stupid bugfix
};
#endif //THEGAME_MENUSTATE_H
