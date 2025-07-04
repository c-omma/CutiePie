#include "floatable.h"

const unsigned int Floatable::floatSpeed = 45;
const float Floatable::floatStep = 5.0f;
const float Floatable::floatAmplitude = 5.0f;

Floatable::Floatable(float x, float y) : x(x), y(y), frameCounter(0), floatingUp(true), baseY(y), floatOffset(0) {}

void Floatable::setPosition(float x, float y) {
    this->x = x;
    this->y = y;

    /* reset animation */
    this->baseY = y;
    this->floatOffset = 0;
    this->frameCounter = 0;
    this->floatingUp = true;
}

void Floatable::draw(sf::RenderWindow &window) {
    floatUpdate();
    drawFloatable(window);
}

void Floatable::floatUpdate() {
    this->frameCounter++;
    
    if (this->frameCounter >= Floatable::floatSpeed) {
        this->frameCounter = 0;

        if (this->floatingUp) {
            this->floatOffset += Floatable::floatStep;
            if (this->floatOffset >= Floatable::floatAmplitude) {
                this->floatingUp = false;
            }
        } else {
            this->floatOffset -= Floatable::floatStep;
            if (this->floatOffset <= -Floatable::floatAmplitude) {
                this->floatingUp = true;
            }
        }

        this->y = this->baseY + this->floatOffset;
    }
}
