#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "canvas.hpp"
#include "brush.hpp"
#include "colorButton.hpp"
#include "settings.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(settings::winWidth, settings::winHeight), "Art Application");

    Canvas canvas(sf::Vector2u(600, 600), sf::Color::White);

    Brush brush;

    Tool* currentTool = &brush;

    std::vector<ColorButton> buttons = {
        ColorButton(sf::Vector2f(10.0f, 10.0f), sf::Color::White),
        ColorButton(sf::Vector2f(10.0f, 110.0f), sf::Color::Red),
        ColorButton(sf::Vector2f(10.0f, 210.0f), sf::Color::Blue),
        ColorButton(sf::Vector2f(10.0f, 310.0f), sf::Color::Yellow),
        ColorButton(sf::Vector2f(10.0f, 410.0f), sf::Color::Green),
        ColorButton(sf::Vector2f(10.0f, 510.0f), sf::Color::Magenta)
    };

    sf::CircleShape clear1(40);
    clear1.setPosition(10, 710);
    clear1.setFillColor(sf::Color::Red);

    sf::CircleShape clear2(30);
    clear2.setPosition(20, 720);
    clear2.setFillColor(sf::Color::Black);

    sf::RectangleShape pallete;
    pallete.setSize(sf::Vector2f(100, 800));
    pallete.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::S)
                {
                    canvas.saveToFile("painting.png");
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2f mousePosition = (sf::Vector2f) sf::Mouse::getPosition(window);
            int mouseX = mousePosition.x;
            int mouseY = mousePosition.y;

            sf::Vector2f canvasMousePosition = mousePosition - canvas.getPosition();

            for (ColorButton& button : buttons)
            {
                if (button.circle.getGlobalBounds().contains(mousePosition))
                {
                    currentTool->setColor(button.color);
                }
            }

            if (clear1.getGlobalBounds().contains(mousePosition))
            {
                canvas.clear();
            }

            if (canvasMousePosition.x > 0 &&
                canvasMousePosition.x < canvas.getRenderTexture().getSize().x &&
                canvasMousePosition.y > 0 &&
                canvasMousePosition.y < canvas.getRenderTexture().getSize().y)
            {
                currentTool->use(window, canvas, canvasMousePosition);
            }
        }

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