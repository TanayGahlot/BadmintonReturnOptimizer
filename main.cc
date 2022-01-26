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
  std::cerr << "Incorrect usage, use it as follows:\n ./ReturnOptimizer <optimizer>\n"
            << "for ex: to use bad optimizer:\n ./ReturnOptimizer bad_optimizer \n\n"
            << "The following optimizers are available as of now:\n"
            << "1. bad_optimizer: returns to the opponent position \n"
            << "2. distance_based_optimizer: returns to position furthest away from opponent. \n"
            << '\n';
  exit(-1);
}

ReturnOptimizer *GetCorrectReturnOptimizerImplementation(char *optimizerName)
{
  if (std::strcmp(optimizerName, "bad_optimizer") == 0)
  {
    return new BadReturnOptimizer;
  }
  else if (std::strcmp(optimizerName, "distance_based_optimizer") == 0)
  {
    return new DistanceBasedReturnOptimizer;
  }
  else
  {
    std::cerr << "The given type of optimizer is not supported: " << optimizerName;
    exit(-1);
  }
}

int main(int argc, char **argv)
{
  ReturnOptimizer *optimizer = new ReturnOptimizer;
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

  position optimalPosition = optimizer->FindBestPositionForReturn(opponentPosition, myPosition);
  DisplayPosition(optimalPosition);
  return 0;
}
