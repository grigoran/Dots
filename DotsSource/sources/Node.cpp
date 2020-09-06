#include "Node.h"

#include <iostream>

Node::Node() {
  team = 0;
  conected = 0;
  marked = 0;
  prev = nullptr;
  next = nullptr;
}

Node::Node(sf::Vector2i coords) {
  team = 0;
  conected = 0;
  marked = 0;
  prev = nullptr;
  next = nullptr;
  meshCoord = coords;
}

void Node::clear() {
  marked = 0;
  team = 0;
  conected = 0;
  prev = nullptr;
  next = nullptr;
}

sf::Vector2i Node::getIndex() { return meshCoord; }

char Node::Team() { return team; }

void Node::Team(char team) { this->team = team; }

Node *Node::getNext() { return next; }

Node *Node::getPrev() { return prev; }


sf::Color Node::getColor() {
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


void Node::conect(Node *prev, Node *next) {
  this->prev = prev;
  this->next = next;
  conected = 1;
}

bool Node::isConected() { return conected; }

void Node::mark() { marked = true; }

void Node::unmark() { marked = false; }

bool Node::isMarked() { return marked; }