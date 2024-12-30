#include "brush.hpp"
#include <SFML/Graphics.hpp>

Brush::Brush()
{
    size = 10;
    color = sf::Color::Black;
}

void Brush::setSize(float newSize)
{
    size = newSize;
}

void Brush::setColor(sf::Color newColor)
{
    color = newColor;
}

void Brush::use(sf::RenderWindow& window, Canvas& canvas, sf::Vector2f mousePosition)
{
    sf::CircleShape stroke(size);
    stroke.setFillColor(color);
    stroke.setOrigin(size, size);
    stroke.setPosition((sf::Vector2f) mousePosition);
    canvas.getRenderTexture().draw(stroke);
    canvas.getRenderTexture().display();
}