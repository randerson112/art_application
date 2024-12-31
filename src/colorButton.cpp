#include "colorButton.hpp"
#include "settings.hpp"
#include <SFML/Graphics.hpp>

//Constructor to set the color, radius, and position of a color button
ColorButton::ColorButton(sf::Vector2f position, sf::Color color) : color(color)
{
    circle.setPosition(position);
    circle.setRadius(settings::colorButtonRadius);
    circle.setFillColor(color);
}