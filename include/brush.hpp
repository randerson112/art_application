#ifndef BRUSH_HPP
#define BRUSH_HPP

#include <SFML/Graphics.hpp>
#include "tool.hpp"

class Brush : public Tool
{
private:
    float size;
    sf::Color color;

public:
    Brush();

    void setSize(float newSize);
    void setColor(sf::Color newColor) override;

    void use(sf::RenderWindow& window, Canvas& canvas, sf::Vector2f mousePosition) override;
};

#endif