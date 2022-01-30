#include "common_data_structure.h"

class Grid
{
public:
    Grid(int length, int width) : grid_length_(length), grid_width_(width) {}
    position FindMaximum(double (*objective_function)(position, position), position opponent_position);

private:
    int grid_length_, grid_width_;
};