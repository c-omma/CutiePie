#ifndef PIE_H
#define PIE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <string>

#include "../../view/character.h"

class Pie : public Character {
    public:
    Pie(float x = 0, float y = 0);

    private:
    static std::vector<std::vector<std::string>> frames;
    static std::vector<unsigned int> frameSpeeds;
    void updateSprite(sf::Event &e) override;
};

#endif // PIE_H
