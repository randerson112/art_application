#include "canvas.hpp"
#include "settings.hpp"
#include <SFML/Graphics.hpp>

//Constructor to create the texture of the canvas and set the backgound color and position
Canvas::Canvas(sf::Vector2u size, sf::Color backgroundColor) : 
backgroundColor(backgroundColor), renderTexture({size.x, size.y}), canvasSprite(renderTexture.getTexture())
{
    renderTexture.clear(backgroundColor);
    renderTexture.display();

    canvasSprite.setPosition(
        {static_cast<float>(settings::winWidth) / 2 - size.x / 2 + 50,
        static_cast<float>(settings::winHeight) / 2 - size.y / 2});
}

//Getter for the private render texture member
sf::RenderTexture& Canvas::getRenderTexture()
{
    return renderTexture;
}

//Getter for the position of the top left of the canvas
sf::Vector2f Canvas::getPosition()
{
    return canvasSprite.getPosition();
}

//Clears the canvas back to blank default background color
void Canvas::clear()
{
    renderTexture.clear(backgroundColor);
    renderTexture.display();
}

//Saves the contents of the canvas to a file
void Canvas::saveToFile(std::string filename)
{
    sf::Image canvasImage = renderTexture.getTexture().copyToImage();
    if (!canvasImage.saveToFile(filename))
    {
        throw std::runtime_error("Failed to save canvas content to file.");
    }
}

//Draw the canvas to the window
void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(canvasSprite, states);
}