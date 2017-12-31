#include "Node.h"
#include <vector>

#ifndef TREE_BUILDER_H
#define TREE_BUILDER_H

class TreeBuilder {
public:
  TreeBuilder(int s, int nbBank, std::vector<int> bankWeigth);
  int getS();
  int getRemainingNodes();
  Node* buildNode();
  void insertNode(Node* n);
  void printNodes();
  void recursivePrint();
  void generateSolution();
  void getLeafHigh(Node* n, int h);
  std::vector<int> getSolution();
  int getSolutionValue();


private:
  std::vector<int> solution;
  std::vector<Node*> nodes;
  int s; // Number of slots of the machine (s-tree)
  int remainingNodes;
  int solutionValue;



};

#endif
