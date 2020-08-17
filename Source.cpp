#include <SFML/Graphics.hpp>
#include <iostream>
#include "field.h"
#include "Dot.h"

int main()
{
    sf::Vector2i resolution(800, 600);
    sf::RenderWindow window(sf::VideoMode(resolution.x,resolution.y), "Dots!");
    window.setFramerateLimit(60);


    sf::View view= window.getView();
    //view.zoom(1.5);
    window.setView(view);
    
    Field field(resolution, 20, 3);
    Dot dots(field.getField(), resolution);

    sf::Vector2i mousepos = sf::Mouse::getPosition(window);

    sf::CircleShape dot(10.0f);
    sf::Color color= sf::Color::Red;
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
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window.close();
            }
        }


        mousepos = sf::Mouse::getPosition(window);
        target = field.getPos(mousepos);
        dst = target- dot.getPosition();

        switch (team)
        {
        case 1:
            color = sf::Color::Red;
            break;
        case 2:
            color = sf::Color::Blue;
            break;
        case 3:
            color = sf::Color::Yellow;
            break;
        case 4:
            color = sf::Color::Green;
            break;
        default:
            break;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (dots.push(target, field.getNode(target),color,team))
                team++;
        }
        if (team > 4) team = 1;
        dot.move(dst*deltaTime.asSeconds()*10.0f);

        window.clear(sf::Color::White);

        window.draw(field);
        dot.setFillColor(color);
        window.draw(dot);
        window.draw(dots);
        window.display();
    }

    return 0;
}