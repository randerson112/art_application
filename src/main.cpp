#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "brush.hpp"
#include "colorButton.hpp"
#include "settings.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(settings::winWidth, settings::winHeight), "Art Application");

    Brush brush;
    std::vector<sf::CircleShape> strokes;

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
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;
            if (mouseX >= 0 && mouseX <= 80 && mouseY >= 0 && mouseY <= 80)
            {
                brush.setColor(sf::Color::White);
            }
            else if (mouseX >= 0 && mouseX <= 80 && mouseY >= 100 && mouseY <= 180)
            {
                brush.setColor(sf::Color::Red);
            }
            else if (mouseX >= 0 && mouseX <= 80 && mouseY >= 200 && mouseY <= 280)
            {
                brush.setColor(sf::Color::Blue);
            }
            else if (mouseX >= 0 && mouseX <= 80 && mouseY >= 300 && mouseY <= 380)
            {
                brush.setColor(sf::Color::Yellow);
            }
            else if (mouseX >= 0 && mouseX <= 80 && mouseY >= 400 && mouseY <= 480)
            {
                brush.setColor(sf::Color::Green);
            }
            else if (mouseX >= 0 && mouseX <= 80 && mouseY >= 500 && mouseY <= 580)
            {
                brush.setColor(sf::Color::Magenta);
            }
            else if (mouseX >= 0 && mouseX <= 80 && mouseY >= 720 && mouseY <= 800)
            {
                strokes.clear();
                window.clear(sf::Color::Black);
            }
            else if (mouseX >= 100 + 30)
            {
                brush.handleActions(window, strokes);
            }
        }

        window.draw(pallete);
        for (sf::CircleShape& stroke : strokes)
        {
            window.draw(stroke);
        }
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