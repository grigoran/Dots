#include <vector>

#include "Field.h"
#include "Line.h"
#include "Node.h"

class Contours : public sf::Drawable{
 public:
  Contours(Field* field);
  void add(Node* start);

 private:
  std::vector<Node*> contours;
  Field* field;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};