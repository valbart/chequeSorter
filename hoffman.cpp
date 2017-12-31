#include "TreeBuilder.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[]) {
  // Test tree build
  // TreeBuilder tb (2, 6, {10, 9, 8, 7, 6, 2});
  // while (tb.getRemainingNodes() > tb.getS()) {
  //   tb.insertNode(tb.buildNode());
  // }
  // tb.recursivePrint();
  // tb.generateSolution();
  // std::vector<int> solution = tb.getSolution();
  // for (unsigned int i = 0; i < 6; ++i) {
  //   std::cout << solution[i] << std::endl;
  // }


  // MAIN PROG
  int s = atoi(argv[1]);
  char* filename = argv[2];
  std::fstream instanceFile(filename ,std::ios_base::in);
  int nbBank;
  instanceFile >> nbBank;
  std::vector<int> bankCheques;
  bankCheques.clear();
  bankCheques.resize(nbBank);
  for (unsigned int i = 0; i < nbBank; ++i) {
    instanceFile >> bankCheques[i];
  }
  TreeBuilder tb(s, nbBank, bankCheques);
  while (tb.getRemainingNodes() > tb.getS()) {
    tb.insertNode(tb.buildNode());
  }
  tb.generateSolution();
  std::vector<int> solution = tb.getSolution();;
  std::ofstream outfile;
  outfile.open("solution.txt", std::ios::out);
  outfile << tb.getSolutionValue() << " ";
  for (unsigned int i = 0; i < nbBank-1; ++i) {
    outfile << solution[i] << " ";
  }
  outfile << solution[nbBank-1];
}
