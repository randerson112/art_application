#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "canvas.hpp"
#include "brush.hpp"
#include "colorButton.hpp"
#include "settings.hpp"

int main()
{
    //Creation of Window, Canvas, and tools
    sf::RenderWindow window(sf::VideoMode(settings::winWidth, settings::winHeight), "Art Application");

    Canvas canvas(settings::canvasSize, sf::Color::White);

    Brush brush;

    Tool* currentTool = &brush;

    //Creation of color buttons and a vector to store them
    std::vector<ColorButton> buttons = {
        ColorButton(sf::Vector2f(10.0f, 10.0f), sf::Color::White),
        ColorButton(sf::Vector2f(10.0f, 110.0f), sf::Color::Red),
        ColorButton(sf::Vector2f(10.0f, 210.0f), sf::Color::Blue),
        ColorButton(sf::Vector2f(10.0f, 310.0f), sf::Color::Yellow),
        ColorButton(sf::Vector2f(10.0f, 410.0f), sf::Color::Green),
        ColorButton(sf::Vector2f(10.0f, 510.0f), sf::Color::Magenta),
        ColorButton(sf::Vector2f(10.0f, 610.0f), sf::Color::Black)
    };

    //Creation of clear button and pallete textures
    sf::CircleShape clear1(40);
    clear1.setPosition(10, 710);
    clear1.setFillColor(sf::Color::Red);

    sf::CircleShape clear2(30);
    clear2.setPosition(20, 720);
    clear2.setFillColor(sf::Color::Black);

    sf::RectangleShape pallete;
    pallete.setSize(sf::Vector2f(100, 800));
    pallete.setFillColor(sf::Color::Cyan);

    //Main loop
    while (window.isOpen())
    {
        //Calculate the mouse position in the window and mouse position on the canvas
        sf::Vector2f mousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);
        sf::Vector2f canvasMousePosition = mousePosition - canvas.getPosition();

        //Event loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            //Window close event
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            //Key pressed events
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::S)
                {
                    canvas.saveToFile("painting.png");
                }
            }

            //Mouse button pressed events
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //Left mouse button clicked event
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //Checks to see if a color button was clicked
                    for (ColorButton& button : buttons)
                    {
                        if (button.circle.getGlobalBounds().contains(mousePosition))
                        {
                            currentTool->setColor(button.color);
                        }
                    }

                    //Checks to see if the clear button was clicked
                    if (clear1.getGlobalBounds().contains(mousePosition))
                    {
                        canvas.clear();
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    dynamic_cast<Brush*>(currentTool)->reset();
                }
            }
        }

        //While left mouse button is pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            //If the mouse position is in the canvas, use the current tool
            if (canvasMousePosition.x > 0 &&
                canvasMousePosition.x < canvas.getRenderTexture().getSize().x &&
                canvasMousePosition.y > 0 &&
                canvasMousePosition.y < canvas.getRenderTexture().getSize().y)
            {
                currentTool->use(window, canvas, canvasMousePosition);
            }
        }

        //Draw the canvas, pallete, color buttons, and clear button to the screen
        window.draw(canvas);
        window.draw(pallete);
        for (ColorButton& button : buttons)
        {
            window.draw(button.circle);
        }
        window.draw(clear1);
        window.draw(clear2);
        window.display();
    }

    return 0;
}