#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include "../classes/typeable.h"
#include "../../view/background.h"

class Level {
    public:
    Level(const sf::RenderWindow &window, unsigned int number);
    void update(sf::Event &e);
    void draw(sf::RenderWindow &window);

    private:
    unsigned int number;
    std::vector<Typeable> typeables;
    Background background;
};

#endif // LEVEL_H
