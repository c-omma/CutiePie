#ifndef FLOATABLE_H
#define FLOATABLE_H

#include <SFML/Graphics.hpp>

class Floatable {
    public:
    Floatable(float x = 0, float y = 0, bool isFloating = true);
    virtual ~Floatable() = default;
    virtual void setPosition(float x, float y);
    void setFloating(bool floating);
    float getX() const { return x; }
    float getY() const { return baseY; }
    void draw(sf::RenderWindow& window);

    protected:
    void floatUpdate();
    virtual void drawFloatable(sf::RenderWindow& window) = 0;
    float x;
    float y;
    float baseY;

    private:
    bool isFloating;
    static const unsigned int floatSpeed; // how many frames between each float step
    static const float floatStep;
    static const float floatAmplitude;
    unsigned int frameCounter;
    bool floatingUp;
    float floatOffset;
};

#endif // FLOATABLE_H
