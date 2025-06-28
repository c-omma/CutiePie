#ifndef TYPEABLE_H
#define TYPEABLE_H

#include "../../view/floatable.h"
#include "../../view/text.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>
#include <map>

class Typeable: public Floatable {
    public:
    Typeable();
    Typeable(const std::string& text, float x = 0, float y = 0);
    static void setTextColor(const sf::Color& color);
    static void setTextTypedColor(const sf::Color& color);
    static void setTextDoneColor(const sf::Color& color);
    static void setFontSize(unsigned int size);
    void setPosition(float x, float y) override;
    void centerHorizontally(const sf::RenderWindow& window);
    bool isDone() const;
    void checkTyping();

    private:
    static const std::map<char, sf::Keyboard::Key> keys;
    static sf::Music keySound;
    static sf::Music lastKeySound;
    static sf::Color textColor;
    static sf::Color textTypedColor;
    static sf::Color textDoneColor;
    static unsigned int fontSize;
    std::string text;
    Text baseText;
    Text typedText;
    unsigned int currentIndex = 0;
    bool done = false;
    void drawFloatable(sf::RenderWindow& window) override;
};

#endif // TYPEABLE_H
