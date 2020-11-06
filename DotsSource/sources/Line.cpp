#include "Line.h"
#include <math.h>
#include <iostream>

Line::Line() {}

void Line::set(sf::Vector2f start, sf::Vector2f end, sf::Color color,
               float progress)
{
  end = start + (end - start) * progress;

  float angle = 0;
  float dy = end.y - start.y;
  float dx = end.x - start.x;

  sf::Vector2f size(sqrt(dy * dy + dx * dx), 3);

  rect.setSize(size);
  rect.setOrigin(sf::Vector2f(0, size.y / 2));
  rect.setPosition(start);
  rect.setFillColor(color);

  if (dx == 0)
    angle = abs(dy) / dy * M_PI_2;
  else if (dy == 0)
    angle = (abs(dx) / dx - 1) / 2 * M_PI;
  else if (dx > 0)
    angle = atanf(dy / dx);
  else
    angle = atanf(dy / dx) + M_PI;

  angle = angle * 180 / M_PI;

  rect.setRotation(angle);
}

void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(rect);
}
