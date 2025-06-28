#include "background.h"

Background::Background() {
    backgroundShape.setSize(sf::Vector2f(800, 600));
    backgroundShape.setFillColor(sf::Color::Black);
}

Background::Background(const std::string& textureFile, const sf::RenderWindow& window) {
    if (!backgroundTexture.loadFromFile(textureFile)) {
        throw std::runtime_error("Background: Failed to load texture from file: " + textureFile);
    }
    backgroundTexture.setRepeated(true);
    backgroundShape.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(backgroundShape);
}
