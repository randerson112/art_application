#ifndef TOOL_HPP
#define TOOL_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "canvas.hpp"

class Tool
{
public:
    virtual void use(sf::RenderWindow& window, Canvas& canvas, sf::Vector2f mousePosition) {};

    virtual void setColor(sf::Color newColor) {};
};

#endif