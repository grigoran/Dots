#include "Dot.h"

#include <iostream>

sf::Color Dot::getColor(char team) {
  switch (team) {
    case 1:
      return sf::Color::Red;
      break;
    case 2:
      return sf::Color::Green;
      break;
    case 3:
      return sf::Color::Blue;
      break;
    case 4:
      return sf::Color::Yellow;
      break;
    default:
      return sf::Color::Black;
      break;
  }
}

Dot::Dot(Field *_field) : radius(7.5), nodes(_field->getField()) {
  field = _field;
  dotTex.create(field->getRes().x, field->getRes().y);
}

Node *Dot::push(sf::Vector2f pos, char team) {
  sf::Vector2i nodePos = field->getNode(pos);
  // nodes.get() вернет ноду с тимой -1, и значит условие не выполнится
  Node *node = nodes.get(nodePos);
  if (node->Team() == 0) {
    drawCircle(pos, team);
    node->Team(team);
    lastNodePos = nodePos;
    findPath(node, node, 0);
    return node;
  }
  return nodes.fake();
}

void Dot::drawCircle(sf::Vector2f pos, char team) {
  sf::CircleShape circle(radius);
  circle.setOrigin(radius, radius);
  circle.setPosition(pos);
  circle.setFillColor(getColor(team));
  dotTex.draw(circle);
  dotTex.display();
  dotsSpr.setTexture(dotTex.getTexture());
}

void Dot::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(dotsSpr);
}

void Dot::clear() {
  dotTex.clear(sf::Color::Transparent);
  nodes.clear();
}

void Dot::undo() {
  nodes.get(lastNodePos)->Team(0);
  redraw();
}

void Dot::redraw() {
  dotTex.clear(sf::Color::Transparent);
  sf::CircleShape circle(radius);
  circle.setOrigin(radius, radius);
  Node *node;
  for (int i = 0; i < field->getField().x; i++) {
    for (int j = 0; j < field->getField().y; j++) {
      node = nodes.get(sf::Vector2i(i, j));
      if (node->Team() != 0) {
        circle.setPosition(field->getPosIndex(i, j));
        circle.setFillColor(getColor(node->Team()));
        dotTex.draw(circle);
      }
    }
  }
}

bool Dot::findPath(Node *node, Node *start, int num) {
  sf::Vector2i index = node->getIndex();
  Node *getedNode;
  node->mark();
  for (int i = 0; i < 8; i++) {
    getedNode = nodes.get(index, i);
    if (getedNode == start && num > 2) {
      getedNode->conect(node, getedNode);
      node->unmark();
      return true;
    }
    if (getedNode->Team() == start->Team() && !getedNode->isConected() &&
        !getedNode->isMarked()) {
      if (findPath(getedNode, start, num + 1)) {
        getedNode->conect(node, getedNode);
        node->unmark();
        return true;
      }
    }
  }
  node->unmark();
  return false;
}
