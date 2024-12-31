#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>

//Contains variables for settings like window and canvas dimensions
namespace settings
{
    const int winWidth = 800;
    const int winHeight = 800;
    const float colorButtonRadius = 40;
    const sf::Vector2u canvasSize = sf::Vector2u(600, 600);
}

#endif