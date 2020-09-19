#include <iostream>
#include <math.h>

#include "Dot.h"
#include "Contours.h"

#define ESCAPE_NORMAL "\x1b[0m"
#define ESCAPE_RED "\x1b[31m"
#define ESCAPE_GREEN "\x1b[32m"

int main()
{
  sf::Vector2i resolution(800, 800);
  sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Dots!");
  window.setFramerateLimit(60);

  sf::View view = window.getView();
  // view.zoom(1.5);
  window.setView(view);
  Field field(resolution, 22, 1);
  Dot dots(&field);

  sf::Vector2i mousepos = sf::Mouse::getPosition(window);
  float radius = 10.0f;
  sf::CircleShape dot(radius); // Dot on cursor
  dot.setFillColor(sf::Color::Red);
  dot.setOrigin(radius, radius);

  sf::Vector2f target;
  sf::Vector2f dst;

  sf::Clock clock;
  sf::Time deltaTime;

  Contours contours(&field);

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
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
          window.close();
          break;

        case sf::Keyboard::Num1:
          team = 1;
          break;

        case sf::Keyboard::Num2:
          team = 2;
          break;

        case sf::Keyboard::Num3:
          team = 3;
          break;

        case sf::Keyboard::Num4:
          team = 4;
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
      Node *node = dots.push(target, team);
      if (node->isConected())
      {
        std::cout << ESCAPE_GREEN << "FIND!\n"
                  << ESCAPE_NORMAL; // Lines push
        contours.add(node);
      }
    }
    contours.update(deltaTime.asSeconds()*3);

    dot.move(dst * deltaTime.asSeconds() * 10.0f);

    window.clear(sf::Color::White);

    window.draw(field);
    dot.setFillColor(Dot::getColor(team));
    window.draw(dot);
    window.draw(dots);
    window.draw(contours);
    window.display();
  }

  return 0;
}
