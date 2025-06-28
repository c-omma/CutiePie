#include "menu.h"

Menu::Menu(const sf::RenderWindow &window)
    : background("assets/images/grass.png", window) {
    Typeable::setTextColor(sf::Color(234, 178, 129));
    Typeable::setTextTypedColor(sf::Color(234, 114, 134));
    Typeable::setTextDoneColor(sf::Color(244, 164, 191));
    Typeable::setFontSize(72);

    play = Typeable("Play", 0, 350);
    play.centerHorizontally(window);
    exit = Typeable("Exit", 0, 500);
    exit.centerHorizontally(window);
    instructions = Text("type to continue...", 0, 700, sf::Color(162, 166, 169), 38);
    instructions.centerHorizontally(window);
}

void Menu::update(sf::Event &e) {
    play.checkTyping();
    exit.checkTyping();
}

void Menu::draw(sf::RenderWindow &window) {
    background.draw(window);
    play.draw(window);
    exit.draw(window);
    instructions.draw(window);
}
