#include "pie.h"

std::vector<std::vector<std::string>> Pie::frames = {
    {"assets/pie/standing/left1.png", "assets/pie/standing/left2.png"},
    {"assets/pie/standing/right1.png", "assets/pie/standing/right2.png"},
    {"assets/pie/flying/left1.png", "assets/pie/flying/left2.png", "assets/pie/flying/left3.png", "assets/pie/flying/left4.png", "assets/pie/flying/left3.png", "assets/pie/flying/left2.png"},
    {"assets/pie/flying/right1.png", "assets/pie/flying/right2.png", "assets/pie/flying/right3.png", "assets/pie/flying/right4.png", "assets/pie/flying/right3.png", "assets/pie/flying/right2.png"}
};

std::vector<unsigned int> Pie::frameSpeeds = {60, 60, 20, 20};

Pie::Pie(float x, float y) : Character(x, y, frames, frameSpeeds, false) {
}

void Pie::updateSprite(sf::Event &e) {
    if (e.type == sf::Event::MouseButtonPressed) {
        if (e.mouseButton.button == sf::Mouse::Left) {
            if (e.mouseButton.x < x) {
                this->setFloating(true);
                currentSpriteIndex = 2;
            } else {
                this->setFloating(true);
                currentSpriteIndex = 3;
            }
        }
    }
}
