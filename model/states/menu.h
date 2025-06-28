#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "../classes/typeable.h"
#include "../../view/text.h"
#include "../../view/background.h"

class Menu {
    public:
    Menu(const sf::RenderWindow &window);
    void update(sf::Event &e);
    void draw(sf::RenderWindow &window);

    private:
    Typeable play;
    Typeable exit;
    Text instructions;
    Background background;
};

#endif // MENU_H
