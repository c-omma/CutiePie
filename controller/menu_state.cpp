#include "menu_state.h"

MenuState::MenuState(const sf::RenderWindow &window) : menu(window) {}

void MenuState::update(sf::Event &e) {
    menu.update(e);
}

void MenuState::draw(sf::RenderWindow &window) {
    menu.draw(window);
}
