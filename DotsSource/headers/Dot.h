#pragma once
#include "Field.h"
#include "NodeWeb.h"
class Dot : public sf::Drawable {
 public:
  Dot(Field* _field);
  Node* push(sf::Vector2f pos, char team);  // add dot
  void clear();                            // clear game field
  void undo();                             // remove last dot
  static sf::Color getColor(char team);    // get color of the team

 private:
  NodeWeb nodes;
  void drawCircle(sf::Vector2f pos, char team);
  bool findPath(Node* node, Node* start, int num);
  float radius;
  Field* field;
  sf::Vector2i lastNodePos;  //позиция последней точки(необходима для ее
                             //удаления при необходимости)
  sf::RenderTexture dotTex;  // texture for dots
  sf::Sprite dotsSpr; // sprite for dots
  void redraw();
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
