#include <SFML/Graphics.hpp>

class Line : public sf::Drawable {
 public:
  Line();
  void set(sf::Vector2f start, sf::Vector2f end, sf::Color color,
           float progress);

 private:
  sf::RectangleShape rect;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};