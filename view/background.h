#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class Background {
    public:
    Background();
    Background(const std::string& textureFile, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    private:
    sf::Texture backgroundTexture;
    sf::RectangleShape backgroundShape;
};

#endif // BACKGROUND_H
