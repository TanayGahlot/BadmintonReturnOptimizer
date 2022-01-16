#include <iostream>
#include "optimizer/bad_optimizer.cc"

using namespace std;


position AskForPosition(){
  position pos;
  std::cout<<"Enter X:";
  std::cin>>pos.x;
  std::cout<<"Enter Y:";
  std::cin>>pos.y;
  return pos;
}

void DisplayPosition(position pos){
  std::cout<<"X: "<<pos.x<<" , Y: "<< pos.y<<"\n";
}

int main(){
  std::cout<<"Welcome to my rudimentary program for optimizing your badminton return!\n";

  std::cout<<"Enter your position:\n";
  position myPosition = AskForPosition();

  std::cout<<"Enter your opponent position:\n";
  position opponentPosition = AskForPosition();

  BadReturnOptimizer optimizer;
  position optimalPosition = optimizer.FindBestPositionForReturn(opponentPosition, myPosition);
  DisplayPosition(optimalPosition);

  return 0;
}
