#ifndef TOOL_HPP
#define TOOL_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tool
{
public:
    virtual void handleActions(sf::RenderWindow& window, std::vector<sf::CircleShape>& strokes) {};
};

#endif