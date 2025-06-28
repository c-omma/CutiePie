#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "menu_state.h"

class Game {
    public:
    Game();
    ~Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    bool isRunning() const;
    void update();
    void draw();
    void quit();

    private:
    GameState* state;
    unsigned int level;
    sf::RenderWindow window;
    bool exit = false;
};

#endif // GAME_H
