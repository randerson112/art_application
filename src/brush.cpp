#include "brush.hpp"
#include <SFML/Graphics.hpp>

//Constructor to set the default size and color of the brush
Brush::Brush()
{
    size = 10;
    color = sf::Color::Black;
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
    sf::CircleShape stroke(size);
    stroke.setFillColor(color);
    stroke.setOrigin(size, size);
    stroke.setPosition((sf::Vector2f) mousePosition);
    canvas.getRenderTexture().draw(stroke);
    canvas.getRenderTexture().display();
}