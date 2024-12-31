#include "colorButton.hpp"
#include "settings.hpp"
#include <SFML/Graphics.hpp>

ColorButton::ColorButton(sf::Vector2f position, sf::Color color) : color(color)
{
    circle.setPosition(position);
    circle.setRadius(settings::colorButtonRadius);
    circle.setFillColor(color);
}