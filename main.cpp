#include <SFML/Graphics.hpp>
#include <iostream>

#include "controller/game.h"
#include "model/typeable.h"

int main() {
    Game game;
    Typeable hello("Hello, World!", 700, 200);

    while (game.isRunning()) {        
        game.update();
        game.draw();
    }

    game.quit();
}