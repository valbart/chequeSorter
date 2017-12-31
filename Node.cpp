#include "Node.h"
#include <iostream>

Node::Node(int weigth, bool isleaf, int ident) {
  totalWeigth = weigth;
  leaf = isleaf;
  nbSon = 0;
  id = ident;
}

Node::Node(const Node &n){
  totalWeigth = n.getWeigth();
  leaf = n.isLeaf();
  id = n.getId();
}

int Node::getWeigth() const {
  return totalWeigth;
}

bool Node::isLeaf() const {
  return leaf;
}

void Node::addSon(Node* n) {
  son.push_back(n);
  nbSon += 1;
  totalWeigth += n->getWeigth();
}

void Node::print() {
  std::cout << "Weigth: " << getWeigth() << ", Nb son: " << nbSon << ", Id: " << id << std::endl;
}

void Node::printSon() {
  for (unsigned int i = 0; i < nbSon; ++i) son[i]->print();
}

void Node::recursivePrint() {
  print();
  for (unsigned int i = 0; i < nbSon; ++i) son[i]->recursivePrint();
}

int Node::getId() const {
  return id;
}

int Node::getNbSon() {
  return nbSon;
}

Node* Node::getSon(int index) {
  return son[index];
}
