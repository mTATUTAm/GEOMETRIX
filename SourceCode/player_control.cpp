#include "all.h"


int move_cooldown = 0;
bool fast_move = false;

int move_dir_x = 0;
int move_dir_y = 0;

void player_update(bool allow_x_move, bool allow_y_move)
{
    player_x = start_x + grid_x * cell_size + (cell_size - player_size) / 2.0f;
    player_y = start_y + grid_y * cell_size + (cell_size - player_size) / 2.0f;

    // 入力受付はクールタイムが無いとき
    if (move_cooldown <= 0)
    {
        fast_move = (STATE(0) & PAD_TRG1);

        if (allow_x_move)
        {
            if (TRG(0) & PAD_LEFT && grid_x > 0)
            {
                if (fast_move) move_dir_x = -1;
                else           grid_x--, music::play(SOUND_MOVE, false);
                move_cooldown = 1;
            }
            else if (TRG(0) & PAD_RIGHT && grid_x < 3)
            {
                if (fast_move) move_dir_x = 1;
                else           grid_x++, music::play(SOUND_MOVE, false);
                move_cooldown = 1;
            }
        }

        if (allow_y_move)
        {
            if (TRG(0) & PAD_UP && grid_y > 0)
            {
                if (fast_move) move_dir_y = -1;
                else           grid_y--, music::play(SOUND_MOVE, false);
                move_cooldown = 1;
            }
            else if (TRG(0) & PAD_DOWN && grid_y < 3)
            {
                if (fast_move) move_dir_y = 1;
                else           grid_y++, music::play(SOUND_MOVE, false);
                move_cooldown = 1;
            }
        }
    }

    // 高速移動：限界まで移動する
    if (fast_move && move_cooldown <= 0)
    {
        bool moved = false;

        if (allow_x_move && move_dir_x != 0)
        {
            while (true)
            {
                int next_x = grid_x + move_dir_x;
                if (0 <= next_x && next_x <= 3)
                {
                    grid_x = next_x;
                    moved = true;
                }
                else
                {
                    move_dir_x = 0; // 行き止まり
                    break;
                }
            }
        }

        if (allow_y_move && move_dir_y != 0)
        {
            while (true)
            {
                int next_y = grid_y + move_dir_y;
                if (0 <= next_y && next_y <= 3)
                {
                    grid_y = next_y;
                    moved = true;
                }
                else
                {
                    move_dir_y = 0; // 行き止まり
                    break;
                }
            }
        }

        if (moved)
        {
            music::play(SOUND_DASH, false);  // ダッシュ音
            move_cooldown = 1;
        }
    }

    if (move_cooldown > 0) move_cooldown--;
}