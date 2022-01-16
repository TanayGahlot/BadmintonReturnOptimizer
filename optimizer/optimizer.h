#include "../common_data_structure.cc"

#define COURT_LENGTH 44
#define COURT_BREADTH 20

class ReturnOptimizer {
   public:
      virtual position FindBestPositionForReturn(position opponentPosition, position myPosition) = 0;
};
