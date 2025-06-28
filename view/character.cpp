#include "character.h"

Character::Character(float x, float y, const std::vector<std::vector<std::string>> &frames, const std::vector<unsigned int> frameSpeeds, float dx, float dy, bool isFloating)
    : Floatable(x, y, isFloating), dx(dx), dy(dy) {
    for (int i = 0; i < (int)frames.size(); i++) {
        auto frameSet = frames[i];
        if (!frameSet.empty()) {
            AnimatedSprite sprite = AnimatedSprite(frameSpeeds[i], frameSet, x, y);
            sprites.push_back(sprite);
        } else {
            throw std::runtime_error("Character: Frame set " + std::to_string(i) + " is empty");
        }
    }
}

void Character::setPosition(float x, float y) {
    Floatable::setPosition(x, y);
    sprites[currentSpriteIndex].setPosition(x, y);
}

void Character::update(sf::Event &e) {
    float x = this->x;
    float y = this->y;
    updateSprite(e);
    sprites[currentSpriteIndex].setPosition(x, y);
}

void Character::drawFloatable(sf::RenderWindow& window) {
    printf("%f %f %f %f\n", x, y, dx, dy);
    x += dx;
    y += dy;
    sprites[currentSpriteIndex].setPosition(x, y);
    sprites[currentSpriteIndex].draw(window);
}

