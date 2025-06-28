#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class AnimatedSprite {
    public:
    AnimatedSprite(unsigned int frameSpeed, const std::vector<std::string> &frameFiles, float x = 0, float y = 0);
    void addFrame(const sf::Texture& texture);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);

    private:
    sf::Sprite sprite;
    std::vector<sf::Texture> frames;
    unsigned int currentFrame;
    unsigned int frameSpeed;
    unsigned int frameCounter;
};

#endif // ANIMATED_SPRITE_H
