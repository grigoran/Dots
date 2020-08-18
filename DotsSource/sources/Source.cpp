#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dot.h"

int main()
{
    sf::Vector2i resolution(900, 900);
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Dots!");
    window.setFramerateLimit(60);

    sf::View view = window.getView();
    //view.zoom(1.5);
    window.setView(view);
    Field field(resolution, 22, 3);
    Dot dots(&field);

    sf::Vector2i mousepos = sf::Mouse::getPosition(window);
    sf::CircleShape dot(10.0f);
    dot.setFillColor(sf::Color::Red);
    dot.setOrigin(10, 10);

    sf::Vector2f target;
    sf::Vector2f dst;

    sf::Clock clock;
    sf::Time deltaTime;

    char team = 1;

    while (window.isOpen())
    {
        deltaTime = clock.getElapsedTime();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;

                case sf::Keyboard::Num1:
                    team=1;
                break;

                case sf::Keyboard::Num2:
                    team=2;
                break;

                case sf::Keyboard::Num3:
                    team=3;
                break;

                case sf::Keyboard::Num4:
                    team=4;
                break;

                case sf::Keyboard::C:
                    dots.clear();
                break;

                case sf::Keyboard::Z:
                    dots.undo();
                break;

                }
            }
        }

        mousepos = sf::Mouse::getPosition(window);
        target = field.getTarget(mousepos);
        dst = target - dot.getPosition();        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            dots.push(target, team);
        }

        dot.move(dst * deltaTime.asSeconds() * 10.0f);

        window.clear(sf::Color::White);

        window.draw(field);
        dot.setFillColor(Dot::getColor(team));
        window.draw(dots);
        window.draw(dot);
        window.display();
    }

    return 0;
}
