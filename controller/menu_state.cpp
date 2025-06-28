#include "menu_state.h"

MenuState::MenuState(){
    hello = Typeable("Hello, World!", 700, 200);
}

void MenuState::update(sf::Event &e) {
    hello.checkTyping();
}

void MenuState::draw(sf::RenderWindow &window) {
    hello.draw(window);
}
