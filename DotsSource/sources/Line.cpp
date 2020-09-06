#include "Line.h"

Line::Line() : line(sf::Lines, 2) {}

void Line::set(sf::Vector2f start, sf::Vector2f end, sf::Color color,
               float progress) {
  end = start + (end - start) * progress;
  line[0] = sf::Vertex(start);
  line[0].color = color;
  line[1] = sf::Vertex(end);
  line[1].color = color;
}

void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(line);
}
