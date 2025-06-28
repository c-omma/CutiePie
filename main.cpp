
#include <SFML/Graphics.hpp>
#include <iostream>

#include "utils.h"
#include "controller/game.h"
#include "model/typeable.h"

int main() {
    Game game;

    sf::Clock clock;
    const sf::Time frameTime = sf::seconds(FRAME_TIME);

    /* game loop */
    while (game.isRunning()) {        
        game.update();
        if (clock.getElapsedTime() >= frameTime) {
            game.draw();
            clock.restart();
        }
    }

    game.quit();
}