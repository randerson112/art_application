#include "brush.hpp"
#include <SFML/Graphics.hpp>

//Constructor to set the default size and color of the brush
Brush::Brush()
{
    size = 10;
    color = sf::Color::Black;
    firstStroke = true;
}

//Set the size of the brush when resizing
void Brush::setSize(float newSize)
{
    size = newSize;
}

//Set the color of the brush when clicking a color button
void Brush::setColor(sf::Color newColor)
{
    color = newColor;
}

//Draws brushstrokes to the canvas when the brush is used
void Brush::use(sf::RenderWindow& window, Canvas& canvas, sf::Vector2f mousePosition)
{
    if (firstStroke)
    {
        lastMouseposition = mousePosition;
        firstStroke = false;
    }

    sf::Vector2f direction = mousePosition - lastMouseposition;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f step = direction / distance;

    for (float i = 0; i < distance; i += size/2)
    {
        sf::CircleShape stroke(size);
        stroke.setFillColor(color);
        stroke.setOrigin(size, size);
        stroke.setPosition(lastMouseposition + step * i);
        canvas.getRenderTexture().draw(stroke);
    }

    lastMouseposition = mousePosition;

    canvas.getRenderTexture().display();
}

void Brush::reset()
{
    firstStroke = true;
}