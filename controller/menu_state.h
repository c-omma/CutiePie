#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game_state.h"
#include "../model/states/menu.h"

class MenuState : public GameState {
    public:
    MenuState(const sf::RenderWindow &window);
    GameAction update(sf::Event &e) override;
    void draw(sf::RenderWindow &window) override;

    private:
    Menu menu;
    bool play = false;
    bool exit = false;
};

#endif // MENU_STATE_H
