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

sf::Font Typeable::font;

const sf::Color Typeable::textColor = sf::Color(255, 255, 255);
const sf::Color Typeable::textTypedColor = sf::Color(0, 0, 255);
const sf::Color Typeable::textDoneColor = sf::Color(255, 255, 0);

Typeable::Typeable(const std::string& text, float x, float y) {
    this->text = text;
    this->x = x;
    this->y = y;

    static bool fontLoaded = false;
    if (!fontLoaded) {
        if (!Typeable::font.loadFromFile("assets/classOf74.ttf")) {
            throw std::runtime_error("Typeable: Failed to load font");
        }
        fontLoaded = true;
    }

    this->displayText.setFont(Typeable::font);
    this->displayText.setString(text);
    this->displayText.setCharacterSize(Typeable::fontSize);
    this->displayText.setFillColor(Typeable::textColor);
    this->displayText.setPosition(x, y);
}

std::string Typeable::getText() const {
    return text;
}

void Typeable::setText(const std::string& text) {
    this->text = text;
    this->currentIndex = 0;
    this->displayText.setString(text);
}

void Typeable::checkTyping() {
    if (currentIndex >= text.size()) {
        if (!done) done = true;
        this->displayText.setFillColor(sf::Color::Green);
        return;
    }

    auto it = Typeable::keys.find(text[currentIndex]);
    if (it == Typeable::keys.end()) return;
    if (sf::Keyboard::isKeyPressed(it->second)) this->currentIndex++;
}

void Typeable::draw(sf::RenderWindow& window) const {
    if (this->done) {
        window.draw(displayText);
        return;
    }

    sf::Text typedText;
    typedText.setFont(Typeable::font);
    typedText.setString(text.substr(0, currentIndex));
    typedText.setCharacterSize(Typeable::fontSize);
    typedText.setPosition(x, y);
    typedText.setFillColor(Typeable::textTypedColor);
    window.draw(displayText);
    window.draw(typedText);
}