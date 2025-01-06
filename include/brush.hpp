#ifndef BRUSH_HPP
#define BRUSH_HPP

#include <SFML/Graphics.hpp>
#include "tool.hpp"

//Brush class that handles brush functionality like painting to the canvas
class Brush : public Tool
{
private:
    float size;
    sf::Color color;
    sf::Vector2f lastMouseposition;
    bool firstStroke;

public:
    Brush();

    void setSize(float newSize);
    void setColor(sf::Color newColor) override;

    void use(sf::RenderWindow& window, Canvas& canvas, sf::Vector2f mousePosition) override;
    void reset();
};

#endif