#include <SFML/Graphics.hpp>
#include <iostream>

#include "game/typeable.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "CutiePie", sf::Style::Close | sf::Style::Titlebar);

    Typeable hello("Hello, World!", 700, 200);

    while (window.isOpen()) {
        sf::Event e;
        
        /* game loop */
        while (window.pollEvent(e)) {
            if (e.type == e.Closed) window.close();
            
            hello.checkTyping();

            window.clear();
            hello.draw(window);

            /* switch to back buffer */
            window.display();
        }
    }
}