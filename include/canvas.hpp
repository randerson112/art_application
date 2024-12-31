#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <SFML/Graphics.hpp>
#include <string>

//Canvas class that acts as a container for the user's artwork
class Canvas : public sf::Drawable
{
private:
    sf::RenderTexture renderTexture;
    sf::Sprite canvasSprite;
    sf::Color backgroundColor;

public:
    Canvas(sf::Vector2u size, sf::Color backgroundColor);

    sf::RenderTexture& getRenderTexture();
    sf::Vector2f getPosition();

    void clear();
    void saveToFile(std::string filename);

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif