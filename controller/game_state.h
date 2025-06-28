#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>

class GameState {
    public:
    virtual ~GameState() = default;
    virtual void update(sf::Event &e) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};

#endif // GAME_STATE_H
