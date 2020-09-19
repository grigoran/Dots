#include <vector>

#include "Field.h"
#include "Line.h"
#include "Node.h"

class Contours : public sf::Drawable{
 public:
  Contours(Field* field);
  void add(Node* start);
  void update(float speed);
 private:
  std::vector<Node*> contours; // ноды начал контуров
  std::vector<bool> contoursStates; //Находится ли контур на этапе плавной прорисовки
  std::vector<int> contoursLenght; //число нод в контуре
  int nowContourDraw; //номер текущего конура, который находится на стадии плавной отрисовки
  int drawNodeNumber; //номер ноды в контуре, который рисуется в данный момент
  float stage; //процесс рисования линии между двумя нодами (от 0 до 1)
  Field* field;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};