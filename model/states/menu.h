#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "../classes/typeable.h"
#include "../../view/text.h"
#include "../../view/background.h"

class Menu {
    public:
    Menu(const sf::RenderWindow &window);
    bool isPlay() const;
    bool isExit() const;
    void update(sf::Event &e);
    void draw(sf::RenderWindow &window);

    private:
    Typeable playTypeable;
    Typeable exitTypeable;
    Text instructions;
    Background background;
};

#endif // MENU_H
