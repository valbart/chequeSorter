#include <vector>

#ifndef NODE_H
#define NODE_H

class Node {
public:
  Node(int weigth, bool isLeaf, int id);
  Node(const Node &);

  void addSon(Node* n);
  int getWeigth() const;
  bool isLeaf() const;
  int nbSon;
  void print();
  void printSon();
  void recursivePrint();
  int getId() const;
  int getNbSon();
  Node* getSon(int index);

private:

  int id;
  int totalWeigth;
  std::vector<Node*> son;
  bool leaf;
};

#endif
