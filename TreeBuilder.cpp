#include "TreeBuilder.h"
#include <iostream>
#include <algorithm>

bool nodeComparator(Node* n1, Node* n2) {
  return n1->getWeigth() >= n2 ->getWeigth();
}

TreeBuilder::TreeBuilder(int nbSpot, int nbBank, std::vector<int> bankWeigth) {
  s = nbSpot;
  remainingNodes = nbBank;
  nodes.clear();
  nodes.resize(nbBank);
  for (unsigned int i = 0; i < nbBank; ++i) {
    nodes[i] = new Node(bankWeigth[i], true, i);
  }
  std::sort(nodes.begin(), nodes.end(), nodeComparator);
  solution.clear();
  solution.resize(nbBank);
  solutionValue = 0;
}

int TreeBuilder::getS() {
  return s;
}

void TreeBuilder::printNodes() {
  for (unsigned int i = 0; i < remainingNodes; ++i) nodes[i]->print();
}

void TreeBuilder::recursivePrint() {
  for (unsigned int i = 0; i < remainingNodes; ++i) nodes[i]->recursivePrint();
}

Node* TreeBuilder::buildNode() {
  if (remainingNodes <= s) return NULL;
  Node* newNode = new Node(0, false, -1);
  for (unsigned int i = remainingNodes-1; i >= remainingNodes - s; i --) {
    (*newNode).addSon(nodes[i]);
  }
  remainingNodes -= s;
  return newNode;
}

void TreeBuilder::insertNode(Node* n) {
  int nodeIndex = remainingNodes;
  while (nodeIndex >= 0 && nodes[nodeIndex]->getWeigth() < n->getWeigth()) {
    nodes[nodeIndex+1] = nodes[nodeIndex];
    nodeIndex--;
  }
  nodes[nodeIndex+1] = n;
  remainingNodes += 1;
}

int TreeBuilder::getRemainingNodes() {
  return remainingNodes;
}

void TreeBuilder::generateSolution() {
  for (unsigned int i = 0; i < remainingNodes; ++i) {
    getLeafHigh(nodes[i], 1);
  }
}

void TreeBuilder::getLeafHigh(Node* n, int h) {
  if (n->isLeaf()) {
    solution[n->getId()] = h;
    solutionValue += h*n->getWeigth();
    return;
  };
  for (unsigned int i = 0; i < n->getNbSon(); ++i) {
    getLeafHigh(n->getSon(i), h+1);
  }
}

std::vector<int> TreeBuilder::getSolution() {
  return solution;
}

int TreeBuilder::getSolutionValue() {
  return solutionValue;
}
