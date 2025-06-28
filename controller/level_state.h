#ifndef LEVEL_STATE_H
#define LEVEL_STATE_H

#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "../model/classes/typeable.h"
#include "../model/states/level.h"

class LevelState: public GameState {
    public:
    LevelState(const sf::RenderWindow &window, unsigned int levelNumber);
    GameAction update(sf::Event &e);
    void draw(sf::RenderWindow &window);

    private:
    Level level;
};

#endif // LEVEL_STATE_H