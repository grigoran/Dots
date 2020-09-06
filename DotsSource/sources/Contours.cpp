#include "Contours.h"

Contours::Contours(Field* _field) {
  field = _field;
  contours.reserve(10);
}

void Contours::add(Node* start) {
  contours.push_back(start);
}

void Contours::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  Node* start;
  Node* now;
  sf::Vector2f startPoint;
  sf::Vector2f endPoint;
  Line line;
  for (int i = 0; i < contours.size(); i++) {
    start = contours[i];
    now = start->getNext();
    while (now != start) {
      startPoint = field->getPosIndex(now->getIndex());
      now = now->getNext();
      endPoint = field->getPosIndex(now->getIndex());
      line.set(startPoint, endPoint, now->getColor(), 1);
      target.draw(line);
    }
  }
}
