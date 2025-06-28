#include "menu.h"

Menu::Menu(const sf::RenderWindow &window)
    : background("assets/images/grass.png", window) {
    Typeable::setTextColor(sf::Color(234, 178, 129));
    Typeable::setTextTypedColor(sf::Color(234, 114, 134));
    Typeable::setTextDoneColor(sf::Color(244, 164, 191));
    Typeable::setFontSize(72);

    playTypeable = Typeable("Play", 0, 350);
    playTypeable.centerHorizontally(window);
    exitTypeable = Typeable("Exit", 0, 500);
    exitTypeable.centerHorizontally(window);
    instructions = Text("type to continue...", 0, 700, sf::Color(162, 166, 169), 38);
    instructions.centerHorizontally(window);
}

bool Menu::isPlay() const {
    return playTypeable.isDone();
}

bool Menu::isExit() const {
    return exitTypeable.isDone();
}

void Menu::update(sf::Event &e) {
    playTypeable.checkTyping();
    exitTypeable.checkTyping();
}

void Menu::draw(sf::RenderWindow &window) {
    background.draw(window);
    playTypeable.draw(window);
    exitTypeable.draw(window);
    instructions.draw(window);
}
