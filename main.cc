#include <iostream>
#include "optimizer/optimizer.h"

using namespace std;

position AskForPosition()
{
  position pos;
  std::cout << "Enter X:";
  std::cin >> pos.x;
  std::cout << "Enter Y:";
  std::cin >> pos.y;
  return pos;
}

void DisplayPosition(position pos)
{
  std::cout << "X: " << pos.x << " , Y: " << pos.y << "\n";
}

void DisplayCLIUsageAndDie()
{
  std::cerr << "Incorrect usage, use it as follows:\n ./a.out <optimizer>\n"
            << "for ex: to use bad optimizer:\n ./a.out bad_optimizer \n\n"
            << "The following optimizers are available as of now:\n"
            << "1. bad_optimizer: returns to the opponent position \n"
            << '\n';
  exit(-1);
}

ReturnOptimizer GetCorrectReturnOptimizerImplementation(char *optimizerName)
{
  if (std::strcmp(optimizerName, "bad_optimizer") == 0)
  {
    return BadReturnOptimizer();
  }
  else
  {
    std::cerr << "The given type of optimizer is not supported: " << optimizerName;
    exit(-1);
  }
}

int main(int argc, char **argv)
{
  ReturnOptimizer optimizer;
  if (argc != 2)
  {
    DisplayCLIUsageAndDie();
  }
  else
  {
    optimizer = GetCorrectReturnOptimizerImplementation(argv[1]);
  }

  std::cout << "Welcome to my rudimentary program for optimizing your badminton return!\n";
  std::cout << "Enter your position:\n";
  position myPosition = AskForPosition();
  std::cout << "Enter your opponent position:\n";
  position opponentPosition = AskForPosition();

  position optimalPosition = optimizer.FindBestPositionForReturn(opponentPosition, myPosition);
  DisplayPosition(optimalPosition);
  return 0;
}
