#include <SFML/Graphics.hpp>

#ifndef COLORBUTTON_HPP
#define COLORBUTTON_HPP

//Color button class that allows the user to change the color of the current tool when clicked
class ColorButton{
public:
    sf::CircleShape circle;
    sf::Color color;

    ColorButton(sf::Vector2f position, sf::Color color);
};

#endif