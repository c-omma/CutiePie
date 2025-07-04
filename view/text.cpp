#include "text.h"

sf::Font Text::font;

Text::Text() {
    static bool fontLoaded = false;
    if (!fontLoaded) {
        if (!Text::font.loadFromFile("assets/classOf74.ttf")) {
            throw std::runtime_error("Texts: Failed to load font");
        }
        fontLoaded = true;
    }

    this->textColor = sf::Color::White;
    this->fontSize = 32;
    
    displayText.setFont(Text::font);
    displayText.setFillColor(this->textColor);
    displayText.setCharacterSize(this->fontSize);
    displayText.setPosition(0, 0);
}

Text::Text(const std::string& text, float x, float y, sf::Color color, unsigned int size) {
    static bool fontLoaded = false;
    if (!fontLoaded) {
        if (!Text::font.loadFromFile("assets/classOf74.ttf")) {
            throw std::runtime_error("Texts: Failed to load font");
        }
        fontLoaded = true;
    }

    this->textColor = color;
    this->fontSize = size;
    
    displayText.setString(text);
    displayText.setFont(Text::font);
    displayText.setFillColor(this->textColor);
    displayText.setCharacterSize(this->fontSize);
    displayText.setPosition(x, y);
}

void Text::setPosition(float x, float y) {
    displayText.setPosition(x, y);
}

void Text::setContent(const std::string& text) {
    displayText.setString(text);
}

float Text::centerHorizontally(const sf::RenderWindow& window) {
    float textWidth = displayText.getLocalBounds().width;
    float positionX = (window.getSize().x - textWidth) / 2;
    displayText.setPosition(positionX, displayText.getPosition().y);

    return positionX;
}

void Text::draw(sf::RenderWindow& window) {
    window.draw(displayText);
}
