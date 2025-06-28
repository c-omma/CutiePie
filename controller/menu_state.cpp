#include "menu_state.h"

MenuState::MenuState(const sf::RenderWindow &window) : menu(window) {}

GameAction MenuState::update(sf::Event &e) {
    menu.update(e);
    if (menu.isPlay()) {
        play = true;
        return NEW_GAME;
    } else if (menu.isExit()) {
        exit = true;
        return EXIT_GAME;
    }
    return NONE;
}

void MenuState::draw(sf::RenderWindow &window) {
    menu.draw(window);
}
