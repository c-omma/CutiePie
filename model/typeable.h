#ifndef TYPEABLE_H
#define TYPEABLE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Typeable {
    public:
    Typeable();
    Typeable(const std::string& text, float x = 0, float y = 0);
    std::string getText() const;
    void setText(const std::string& text);
    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
        displayText.setPosition(x, y);
    }
    void checkTyping();
    void draw(sf::RenderWindow& window) const;

    private:
    static const std::map<char, sf::Keyboard::Key> keys;
    static sf::Font font;
    static const sf::Color textColor;
    static const sf::Color textTypedColor;
    static const sf::Color textDoneColor;
    static const unsigned int fontSize = 32;
    sf::Text displayText;
    std::string text;
    unsigned int currentIndex = 0;
    bool done = false;
    float x;
    float y;
};

#endif // TYPEABLE_H