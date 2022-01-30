#include "grid.h"

#define LENGTH_AT_WHICH_OPP_COURT_BEGINS 22.0
#define LENGTH_OF_OPPONENT_COURT 44.0
#define WIDTH_OF_OPPONENT_COURT 20.0

position Grid::FindMaximum(double (*objective_function)(position, position), position opponent_position)
{
    double highest_value = 0;
    position best_position = position(0, 22);
    for (int i = 0; i < grid_length_; i++)
    {
        for (int j = 0; j < grid_width_; j++)
        {
            double x = j * WIDTH_OF_OPPONENT_COURT / grid_width_ ;
            double y = LENGTH_AT_WHICH_OPP_COURT_BEGINS + (i * LENGTH_OF_OPPONENT_COURT / grid_length_);
            position grid_position(x, y);
            double current_value = objective_function(grid_position, opponent_position);
            if (current_value > highest_value)
            {
                highest_value = current_value;
                best_position = grid_position;
            }
        }
    }
    return best_position;
}