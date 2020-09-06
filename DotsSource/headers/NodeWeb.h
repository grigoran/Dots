#include "Node.h"

#define NODE_DIR_R 0
#define NODE_DIR_DR 1
#define NODE_DIR_D 2
#define NODE_DIR_DL 3
#define NODE_DIR_L 4
#define NODE_DIR_UL 5
#define NODE_DIR_U 6
#define NODE_DIR_UR 7
#define NODE_DIR_NONE 8

class NodeWeb{
 public:
  NodeWeb(sf::Vector2i size);
  ~NodeWeb();
  void clear();
  Node* get(sf::Vector2i index);
  Node* get(sf::Vector2i node, int dir);
  Node* fake();
 private:
  Node fakeNode;
  sf::Vector2i meshSize;
  Node** nodes;
};