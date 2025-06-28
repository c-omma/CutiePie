#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <string>

class Text {
    public:
    Text();
    Text(const std::string& text, float x = 0, float y = 0, sf::Color color = sf::Color::White, unsigned int size = 30);
    void setPosition(float x, float y);
    void setContent(const std::string& text);
    void draw(sf::RenderWindow& window);

    private:
    static sf::Font font;
    sf::Text displayText;
    sf::Color textColor;
    unsigned int fontSize;
};

#endif // TEXT_H
