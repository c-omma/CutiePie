#include "level.h"

Level::Level(const sf::RenderWindow &window, unsigned int number) : number(number), background("assets/images/sky.png", window) {
    Typeable::setTextColor(sf::Color(119, 127, 143));
    Typeable::setTextTypedColor(sf::Color(160, 124, 167));
    Typeable::setTextDoneColor(sf::Color(234, 114, 134));
    Typeable::setFontSize(48);
    
    Typeable typeable1("Words are cool!", 0, 500);
    typeable1.centerHorizontally(window);
    typeables.push_back(typeable1);
}

void Level::update(sf::Event &e) {
    for (auto &typeable : typeables) {
        typeable.checkTyping();
    }
}

void Level::draw(sf::RenderWindow &window) {
    background.draw(window);
    for (auto &typeable : typeables) {
        typeable.draw(window);
    }
}
