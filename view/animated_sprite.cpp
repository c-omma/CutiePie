#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite(unsigned int frameSpeed, const std::vector<std::string> &frameFiles, float x, float y)
    : currentFrame(0), frameSpeed(frameSpeed), frameCounter(0) {
    for (const auto& file : frameFiles) {
        sf::Texture texture;
        if (texture.loadFromFile(file)) {
            frames.push_back(texture);
        } else {
            throw std::runtime_error("AnimatedSprite: Failed to load texture from " + file);
        }
    }
    if (!frames.empty()) {
        sprite.setTexture(frames[0]);
    } else {
        throw std::runtime_error("AnimatedSprite: No frames loaded");
    }

    sprite.setPosition(x, y);
}

void AnimatedSprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void AnimatedSprite::draw(sf::RenderWindow& window) {
    this->frameCounter++;

    if (this->frameCounter >= this->frameSpeed) {
        this->frameCounter = 0;
        this->currentFrame = (this->currentFrame + 1) % this->frames.size();
        sprite.setTexture(frames[this->currentFrame]);
    }

    window.draw(sprite);
}
