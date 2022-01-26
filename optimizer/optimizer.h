#include "../data_structure/common_data_structure.h"

#define COURT_LENGTH 44
#define COURT_BREADTH 20

class ReturnOptimizer
{
public:
  virtual position FindBestPositionForReturn(position opponentPosition, position myPosition)
  {
    // defaulting the implementation to be bad implementation where we
    // return to where the opponent player is.
    return opponentPosition;
  };
};

class BadReturnOptimizer : public ReturnOptimizer
{
public:
  position FindBestPositionForReturn(position opponentPosition, position myPosition) override;
};

class DistanceBasedReturnOptimizer : public ReturnOptimizer
{
public:
  position FindBestPositionForReturn(position opponentPosition, position myPosition) override;

private:
  double FindDistance(position pos1, position pos2);
};