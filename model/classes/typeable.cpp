#include "typeable.h"
#include <stdexcept>

const std::map<char, sf::Keyboard::Key> Typeable::keys = {
    {'a', sf::Keyboard::A}, {'b', sf::Keyboard::B}, {'c', sf::Keyboard::C},
    {'d', sf::Keyboard::D}, {'e', sf::Keyboard::E}, {'f', sf::Keyboard::F},
    {'g', sf::Keyboard::G}, {'h', sf::Keyboard::H}, {'i', sf::Keyboard::I},
    {'j', sf::Keyboard::J}, {'k', sf::Keyboard::K}, {'l', sf::Keyboard::L},
    {'m', sf::Keyboard::M}, {'n', sf::Keyboard::N}, {'o', sf::Keyboard::O},
    {'p', sf::Keyboard::P}, {'q', sf::Keyboard::Q}, {'r', sf::Keyboard::R},
    {'s', sf::Keyboard::S}, {'t', sf::Keyboard::T}, {'u', sf::Keyboard::U},
    {'v', sf::Keyboard::V}, {'w', sf::Keyboard::W}, {'x', sf::Keyboard::X},
    {'y', sf::Keyboard::Y}, {'z', sf::Keyboard::Z},
    {'A', sf::Keyboard::A}, {'B', sf::Keyboard::B}, {'C', sf::Keyboard::C},
    {'D', sf::Keyboard::D}, {'E', sf::Keyboard::E}, {'F', sf::Keyboard::F},
    {'G', sf::Keyboard::G}, {'H', sf::Keyboard::H}, {'I', sf::Keyboard::I},
    {'J', sf::Keyboard::J}, {'K', sf::Keyboard::K}, {'L', sf::Keyboard::L},
    {'M', sf::Keyboard::M}, {'N', sf::Keyboard::N}, {'O', sf::Keyboard::O},
    {'P', sf::Keyboard::P}, {'Q', sf::Keyboard::Q}, {'R', sf::Keyboard::R},
    {'S', sf::Keyboard::S}, {'T', sf::Keyboard::T}, {'U', sf::Keyboard::U},
    {'V', sf::Keyboard::V}, {'W', sf::Keyboard::W}, {'X', sf::Keyboard::X},
    {'Y', sf::Keyboard::Y}, {'Z', sf::Keyboard::Z},
    {'0', sf::Keyboard::Num0}, {'1', sf::Keyboard::Num1},
    {'2', sf::Keyboard::Num2}, {'3', sf::Keyboard::Num3},
    {'4', sf::Keyboard::Num4}, {'5', sf::Keyboard::Num5},
    {'6', sf::Keyboard::Num6}, {'7', sf::Keyboard::Num7},
    {'8', sf::Keyboard::Num8}, {'9', sf::Keyboard::Num9},
    {' ', sf::Keyboard::Space}, {',', sf::Keyboard::Comma},
    {'.', sf::Keyboard::Period}, {'!', sf::Keyboard::Num1}, {'-', sf::Keyboard::Dash}
};

sf::Color Typeable::textColor = sf::Color(255, 255, 255);
sf::Color Typeable::textTypedColor = sf::Color(0, 0, 255);
sf::Color Typeable::textDoneColor = sf::Color(255, 255, 0);
unsigned int Typeable::fontSize = 32;

Typeable::Typeable() {
    this->text = "";
    this->x = 0;
    this->y = 0;
    this->done = false;
    this->currentIndex = 0;
    
    baseText = Text();
    typedText = Text();
}

Typeable::Typeable(const std::string& text, float x, float y) : Floatable(x, y) {
    this->text = text;
    this->done = false;
    this->currentIndex = 0;

    baseText = Text(text, x, y, Typeable::textColor, Typeable::fontSize);
    typedText = Text("", x, y, Typeable::textTypedColor, Typeable::fontSize);
}

void Typeable::setTextColor(const sf::Color& color) {
    Typeable::textColor = color;
}

void Typeable::setTextTypedColor(const sf::Color& color) {
    Typeable::textTypedColor = color;
}

void Typeable::setTextDoneColor(const sf::Color& color) {
    Typeable::textDoneColor = color;
}

void Typeable::setFontSize(unsigned int size) {
    Typeable::fontSize = size;
}

void Typeable::setPosition(float x, float y) {
    Floatable::setPosition(x, y);
    baseText.setPosition(x, y);
    typedText.setPosition(x, y);
}

void Typeable::centerHorizontally(const sf::RenderWindow& window) {
    float x = baseText.centerHorizontally(window);
    this->setPosition(x, this->y);
}

void Typeable::checkTyping() {
    if (currentIndex >= text.size()) {
        if (!done) done = true;
        baseText = Text(text, this->x, this->y, Typeable::textDoneColor, Typeable::fontSize);
        return;
    }

    auto it = Typeable::keys.find(text[currentIndex]);
    if (it == Typeable::keys.end()) return;
    if (sf::Keyboard::isKeyPressed(it->second)) {
        typedText.setContent(text.substr(0, currentIndex + 1));
        currentIndex++;
    }
}

void Typeable::drawFloatable(sf::RenderWindow &window) {
    baseText.setPosition(x, y);
    typedText.setPosition(x, y);
    baseText.draw(window);

    if (done) return;
    typedText.draw(window);
}
