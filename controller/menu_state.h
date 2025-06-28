#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game_state.h"

class MenuState : public GameState {
    public:
    MenuState();
    void update(sf::Event &e) override;
    void draw(sf::RenderWindow &window) override;
};

#endif // MENU_STATE_H
