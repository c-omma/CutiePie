#include "menu.h"

Menu::Menu(const std::string &playText, const std::string &exitText, const std::string &instructionsText, const sf::RenderWindow &window)
    : play(playText, 100, 100), exit(exitText, 100, 200), instructions(instructionsText, 100, 300), background("assets/images/grass.png", window) {
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
