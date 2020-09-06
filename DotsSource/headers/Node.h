#pragma once
#include <SFML/Graphics.hpp>

class Node {
 public:
  Node();
  Node(sf::Vector2i coords);
  void clear();
  sf::Vector2i getIndex();
  bool isConected();
  void conect(Node* prev, Node* next);
  Node* getNext();
  Node* getPrev();
  char Team();           // getTeam
  void Team(char team);  // setTeam
  void mark();
  void unmark();
  bool isMarked();
  sf::Color getColor();

 private:
  sf::Vector2i meshCoord;
  char team;  // team
  bool conected;
  bool marked;
  Node* prev;
  Node* next;
};