#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "floatable.h"
#include "animated_sprite.h"

class Character : public Floatable {
    public:
    Character(float x, float y, const std::vector<std::vector<std::string>> &frames, const std::vector<unsigned int> frameSpeeds, bool isFloating = false);
    void setPosition(float x, float y) override;
    virtual void update();
    void drawFloatable(sf::RenderWindow& window) override;

    protected:
    virtual void updateSprite() = 0;
    std::vector<AnimatedSprite> sprites;
    unsigned int currentSpriteIndex = 0;
};

#endif // CHARACTER_H
