#include <SFML/Graphics.hpp>

#ifndef COLORBUTTON_HPP
#define COLORBUTTON_HPP

class ColorButton{
public:
    sf::CircleShape circle;

    ColorButton(sf::Vector2f position, sf::Color color);
};

#endif