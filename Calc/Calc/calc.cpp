#include "calc.h"

int main(int argc, char* argv[]) {

  if(argc!=2){
      error("Incorrect input");
      return 1;
  }

  std::istringstream input(argv[1]);
  std::cout << std::setprecision(3) << calc(input) << std::endl;

  return errorsNum;
}
