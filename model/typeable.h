#ifndef TYPEABLE_H
#define TYPEABLE_H

#include "../view/floatable.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Typeable: public Floatable {
    public:
    Typeable(const std::string& text, float x = 0, float y = 0);
    std::string getText() const;
    void setText(const std::string& text);
    void setPosition(float x, float y) override;
    void checkTyping();

    private:
    static const std::map<char, sf::Keyboard::Key> keys;
    static sf::Font font;
    static const sf::Color textColor;
    static const sf::Color textTypedColor;
    static const sf::Color textDoneColor;
    static const unsigned int fontSize = 32;
    sf::Text displayText;
    sf::Text typedText;
    std::string text;
    unsigned int currentIndex = 0;
    bool done = false;
    void drawFloatable(sf::RenderWindow& window) override;
};

#endif // TYPEABLE_H
