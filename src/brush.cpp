#include "brush.hpp"
#include <SFML/Graphics.hpp>

Brush::Brush()
{
    size = 10;
    color = sf::Color::White;
}

void Brush::setSize(float newSize)
{
    size = newSize;
}

void Brush::setColor(sf::Color newColor)
{
    color = newColor;
}

void Brush::handleActions(sf::RenderWindow& window, std::vector<sf::CircleShape>& strokes)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::CircleShape stroke(size);
        stroke.setFillColor(color);
        stroke.setOrigin(size, size);
        stroke.setPosition((sf::Vector2f) mousePosition);
        strokes.push_back(stroke);
    }
}