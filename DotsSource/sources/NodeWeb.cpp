#include "NodeWeb.h"

NodeWeb::NodeWeb(sf::Vector2i size) {
  fakeNode.Team(-1);
  nodes = new Node*[size.x];
  meshSize = size;
  for (int i = 0; i < size.x; i++) {
    nodes[i] = new Node[size.y];
    for (int j = 0; j < size.y; j++) {
      nodes[i][j] = Node(sf::Vector2i(i, j));
    }
  }
}

NodeWeb::~NodeWeb() {
  for (int i = 0; i < meshSize.x; i++) {
    delete[] nodes[i];
  }
  delete[] nodes;
}

Node* NodeWeb::fake() { return &fakeNode; }

void NodeWeb::clear() {
  for (int i = 0; i < meshSize.x; i++) {
    for (int j = 0; j < meshSize.y; j++) {
      nodes[i][j].clear();
    }
  }
}

Node* NodeWeb::get(sf::Vector2i index) {
  if (index.y < 0 || index.y >= meshSize.y || index.x < 0 ||
      index.x >= meshSize.x)
    return &fakeNode;
  return &nodes[index.x][index.y];
}

Node* NodeWeb::get(sf::Vector2i node, int dir) {
  switch (dir) {
    case NODE_DIR_U:
      if (node.y == 0) return &fakeNode;
      return &nodes[node.x][--node.y];
      break;
    case NODE_DIR_UR:
      if (node.y == 0 || node.x == meshSize.x - 1) return &fakeNode;
      return &nodes[++node.x][--node.y];
      break;
    case NODE_DIR_R:
      if (node.x == meshSize.x - 1) return &fakeNode;
      return &nodes[++node.x][node.y];
      break;
    case NODE_DIR_DR:
      if (node.x == meshSize.x - 1 || node.y == meshSize.y - 1)
        return &fakeNode;
      return &nodes[++node.x][++node.y];
      break;
    case NODE_DIR_D:
      if (node.y == meshSize.y - 1) return &fakeNode;
      return &nodes[node.x][++node.y];
      break;
    case NODE_DIR_DL:
      if (node.x == 0 || node.y == meshSize.y - 1) return &fakeNode;
      return &nodes[--node.x][++node.y];
      break;
    case NODE_DIR_L:
      if (node.x == 0) return &fakeNode;
      return &nodes[--node.x][node.y];
      break;
    case NODE_DIR_UL:
      if (node.x == 0 || node.y == 0) return &fakeNode;
      return &nodes[--node.x][--node.y];
      break;
    default:
      return &fakeNode;
      break;
  }
}