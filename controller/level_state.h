#ifndef LEVEL_STATE_H
#define LEVEL_STATE_H

#include <SFML/Graphics.hpp>
#include "../model/typeable.h"

class LevelState {
    public:
    LevelState();
    void update(sf::Event &e);
    void draw(sf::RenderWindow &window);

    private:
    Typeable hello;
};

#endif // LEVEL_STATE_H