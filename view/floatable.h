#ifndef FLOATABLE_H
#define FLOATABLE_H

#include <SFML/Graphics.hpp>

class Floatable {
    public:
    Floatable(float x = 0, float y = 0);
    virtual ~Floatable() = default;
    virtual void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);

    protected:
    void floatUpdate();
    virtual void drawFloatable(sf::RenderWindow& window) = 0;
    float x;
    float y;

    private:
    static const unsigned int floatSpeed; // how many frames between each float step
    static const float floatStep;
    static const float floatAmplitude;
    unsigned int frameCounter;
    bool floatingUp;
    float baseY;
    float floatOffset;
};

#endif // FLOATABLE_H
