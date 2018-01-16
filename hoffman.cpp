#include "TreeBuilder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main(int argc, char * argv[]) {
  // Gathering arguments and data
  int s = atoi(argv[1]);
  char* filename = argv[2];
  std::fstream instanceFile(filename ,std::ios_base::in);
  int nbBank;
  instanceFile >> nbBank;

  // Computing number of dummy banks to add in order to obtain a s-tree
  // If s = 2 there is no need to add dummy banks
  int nbDummy = 0;
  if (s > 2) {
    int rest = nbBank - (s-1)*(floor(nbBank/(s-1)));
    if (rest == 0) nbDummy = 1;
    else if (rest > 1) nbDummy = s - rest;
  }
  nbBank += nbDummy;

  // Initializing vector for TreeBuilder
  std::vector<int> bankCheques;
  bankCheques.clear();
  bankCheques.resize(nbBank);
  for (unsigned int i = 0; i < nbBank-nbDummy; ++i) {
    instanceFile >> bankCheques[i];
  }
  for (unsigned int i = nbBank-nbDummy; i < nbBank; ++i) bankCheques[i] = 0;

  // Building TreeBuilder instance and Hoffman tree
  TreeBuilder tb(s, nbBank, bankCheques);
  while (tb.getRemainingNodes() > tb.getS()) {
    tb.insertNode(tb.buildNode());
  }

  // Generating solution (gather the final height of banks) and writting solution file
  // Without writting height of dummy banks.
  tb.generateSolution();
  std::vector<int> solution = tb.getSolution();
  std::ofstream outfile;
  outfile.open("solution.txt", std::ios::out);
  outfile << tb.getSolutionValue() << " ";
  for (unsigned int i = 0; i < nbBank-nbDummy-1; ++i) {
    outfile << solution[i] << " ";
  }
  outfile << solution[nbBank-nbDummy-1];
}
