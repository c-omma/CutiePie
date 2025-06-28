#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "floatable.h"
#include "animated_sprite.h"

class Character : public Floatable {
    public: 
    Character(float x, float y, const std::vector<std::vector<std::string>> &frames, const std::vector<unsigned int> frameSpeeds, float dx = 0, float dy = 0, bool isFloating = false);
    void setPosition(float x, float y) override;
    void update(sf::Event &e);
    
    protected:
    void drawFloatable(sf::RenderWindow& window) override;
    virtual void updateSprite(sf::Event &e) = 0;
    std::vector<AnimatedSprite> sprites;
    unsigned int currentSpriteIndex = 0;
    float dx;
    float dy;
};

#endif // CHARACTER_H
