
#include <SFML/Graphics.hpp>
#include <iostream>

#include "utils.h"
#include "model/typeable.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "CutiePie", sf::Style::Close | sf::Style::Titlebar);

    Typeable hello("hello, world", 700, 200);

    sf::Clock clock;
    const sf::Time frameTime = sf::seconds(FRAME_TIME);

    /* game loop */
    while (window.isOpen()) {
        sf::Event e;
            
        /* handle events */
        while (window.pollEvent(e)) {
            if (e.type == e.Closed) window.close();
            
            hello.checkTyping();
        }

        /* update view */
        if (clock.getElapsedTime() >= frameTime) {
            window.clear();
            hello.draw(window);
            window.display();
            
            clock.restart();
        }
    }
}