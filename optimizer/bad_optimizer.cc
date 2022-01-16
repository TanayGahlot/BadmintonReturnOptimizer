#include "optimizer.h"

class BadReturnOptimizer: public ReturnOptimizer {
   public:
      position FindBestPositionForReturn(position opponentPosition, position myPosition) {
         return opponentPosition;
      }
};
