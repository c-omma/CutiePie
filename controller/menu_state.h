#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game_state.h"
#include "../model/typeable.h"

class MenuState : public GameState {
    public:
    MenuState();
    void update(sf::Event &e) override;
    void draw(sf::RenderWindow &window) override;

    private:
    Typeable hello;
};

#endif // MENU_STATE_H
