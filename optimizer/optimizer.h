#include "../common_data_structure.cc"

#define COURT_LENGTH 44
#define COURT_BREADTH 20

class ReturnOptimizer
{
public:
  position FindBestPositionForReturn(position opponentPosition, position myPosition)
  {
    // defaulting the implementation to be bad implementation where we
    // return to where the opponent player is.
    return opponentPosition;
  };
};
