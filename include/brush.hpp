#ifndef BRUSH_HPP
#define BRUSH_HPP

#include <SFML/Graphics.hpp>
#include "tool.hpp"

class Brush : public Tool
{
private:
    float size;
    sf::Color color;

public:
    Brush();

    void setSize(float newSize);
    void setColor(sf::Color newColor);

    void handleActions(sf::RenderWindow& window, std::vector<sf::CircleShape>& strokes) override;
};

#endif