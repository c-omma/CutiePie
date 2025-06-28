#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>

typedef enum {
    NONE,
    NEW_GAME,
    LOAD_GAME,
    EXIT_GAME
} GameAction;

class GameState {
    public:
    virtual ~GameState() = default;
    virtual GameAction update(sf::Event &e) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};

#endif // GAME_STATE_H
