#ifndef PLAYER_CONTROL_H
#define PLAYER_CONTROL_H

extern bool fast_move;
extern int move_dir_x;
extern int move_dir_y;
extern int prev_grid_x;
extern int prev_grid_y;

//Function Prototype Declaration
void player_update(bool allow_x_move, bool allow_y_move);

#endif 