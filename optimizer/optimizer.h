#include "../data_structure/common_data_structure.h"

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

class BadReturnOptimizer : public ReturnOptimizer
{
public:
  position FindBestPositionForReturn(position opponentPosition, position myPosition);
};