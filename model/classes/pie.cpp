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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        dx = e.mouseButton.x + sprites[0].getSprite().getGlobalBounds().width / 2 - this->x;
        dy = e.mouseButton.y + sprites[0].getSprite().getGlobalBounds().height / 2 - this->y;
        dx /= 100;
        dy /= 100;
        if (dx < 0) {
            currentSpriteIndex = 2;
        } else {
            currentSpriteIndex = 3;
        }
    } else {
        dx = 0;
        dy = 0;
    }
}
