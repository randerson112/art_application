#include "canvas.hpp"
#include "settings.hpp"
#include <SFML/Graphics.hpp>

Canvas::Canvas(sf::Vector2u size, sf::Color backgroundColor) : backgroundColor(backgroundColor)
{
    if (!renderTexture.create(size.x, size.y))
    {
        throw std::runtime_error("Failed to create render texture.");
    }

    renderTexture.clear(backgroundColor);
    renderTexture.display();

    canvasSprite.setTexture(renderTexture.getTexture());
    canvasSprite.setPosition(settings::winWidth/2 - size.x/2 + 50, settings::winHeight/2 - size.y/2);
}

sf::RenderTexture& Canvas::getRenderTexture()
{
    return renderTexture;
}

sf::Vector2f Canvas::getPosition()
{
    return canvasSprite.getPosition();
}

void Canvas::clear()
{
    renderTexture.clear(backgroundColor);
    renderTexture.display();
}

void Canvas::saveToFile(std::string filename)
{
    sf::Image canvasImage = renderTexture.getTexture().copyToImage();
    if (!canvasImage.saveToFile(filename))
    {
        throw std::runtime_error("Failed to save canvas content to file.");
    }
}

void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(canvasSprite, states);
}