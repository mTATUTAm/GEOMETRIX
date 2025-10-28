#include "all.h"


int nadenna_eazy_game_state;
int music_timer;


#define MAX_LOGS 100
int log_times_eazy[MAX_LOGS];
int log_x_eazy[MAX_LOGS];
int log_y_eazy[MAX_LOGS];
int log_count_eazy = 0;


Note notes[] = {
    { 105, 0, VECTOR2(0,0), VECTOR2()},
    { 204, 1, VECTOR2(1,0), VECTOR2(1,0)},
    { 303, 0, VECTOR2(1,0), VECTOR2()},
    { 402, 1, VECTOR2(0,0), VECTOR2(-1,0)},
    { 502, 0, VECTOR2(0,0), VECTOR2()},
    { 551, 0, VECTOR2(0,1), VECTOR2()},
    { 601, 0, VECTOR2(0,2), VECTOR2()},
    { 701, 0, VECTOR2(0,2), VECTOR2()},
    { 751, 0, VECTOR2(1,2), VECTOR2()},
    { 800, 0, VECTOR2(2,2), VECTOR2()},

    { 900, 2, VECTOR2(2,1), VECTOR2(0,-1), VECTOR2(0,-1)},
    { 903, 2, VECTOR2(2,0), VECTOR2(0,-2), VECTOR2(0,-1)},

    { 903, 0, VECTOR2(2,0), VECTOR2()},
    { 997, 0, VECTOR2(1, 0), VECTOR2() },
    { 1098, 0, VECTOR2(2, 0), VECTOR2() },
    { 1149, 0, VECTOR2(3, 0), VECTOR2() },
    { 1202-5, 1, VECTOR2(3, 1), VECTOR2(0,1) },
    { 1227-5, 1, VECTOR2(2, 1), VECTOR2(-1,0) },
    { 1251-5, 1, VECTOR2(1, 1), VECTOR2(-1,0) },
    { 1299, 0, VECTOR2(0, 1), VECTOR2() },
    { 1396, 0, VECTOR2(0, 0), VECTOR2() },
    { 1497, 0, VECTOR2(1, 0), VECTOR2() },
    { 1547, 0, VECTOR2(2, 0), VECTOR2() },
    { 1596-5, 1, VECTOR2(2, 1), VECTOR2(0,1) },
    { 1624-5, 1, VECTOR2(2, 2), VECTOR2(0,1) },
    { 1646-5, 1, VECTOR2(2, 3), VECTOR2(0,1) },
    
    { 1696, 0, VECTOR2(1, 3), VECTOR2() },
    { 1743, 0, VECTOR2(1, 2), VECTOR2() },
    { 1794, 0, VECTOR2(2, 2), VECTOR2() },
    { 1844, 0, VECTOR2(3, 2), VECTOR2() },
    { 1867, 0, VECTOR2(2, 2), VECTOR2() }, 
    { 1892, 0, VECTOR2(1, 2), VECTOR2() }, 
    { 1941, 0, VECTOR2(0, 2), VECTOR2() }, 
    { 1992, 0, VECTOR2(0, 1), VECTOR2() },
    { 2042, 0, VECTOR2(1, 1), VECTOR2() }, 
    { 2068, 0, VECTOR2(2, 1), VECTOR2() }, 
    { 2092, 0, VECTOR2(3, 1), VECTOR2() },
    { 2142, 0, VECTOR2(3, 2), VECTOR2() },
    { 2167, 0, VECTOR2(2, 2), VECTOR2() },
    { 2194, 0, VECTOR2(1, 2), VECTOR2() },
    { 2218, 0, VECTOR2(1, 3), VECTOR2() }, 
    { 2243, 0, VECTOR2(0, 3), VECTOR2() },
    { 2292, 0, VECTOR2(0, 2), VECTOR2() },
    { 2343, 0, VECTOR2(0, 1), VECTOR2() }, 
    { 2392, 0, VECTOR2(0, 0), VECTOR2() }, 
    { 2405, 0, VECTOR2(0, 0), VECTOR2() }, 
    { 2419, 0, VECTOR2(1, 0), VECTOR2() },
    { 2432, 0, VECTOR2(1, 0), VECTOR2() }, 
    { 2444, 0, VECTOR2(2, 0), VECTOR2() },
    { 2457, 0, VECTOR2(2, 0), VECTOR2() }, 
    { 2468, 0, VECTOR2(3, 0), VECTOR2() }, 
    { 2482, 0, VECTOR2(3, 0), VECTOR2() }, 
    { 2494, 0, VECTOR2(3, 0), VECTOR2() }, 
    { 2535, 0, VECTOR2(2, 0), VECTOR2() },
    { 2586, 0, VECTOR2(2, 1), VECTOR2() },
    { 2611, 0, VECTOR2(1, 1), VECTOR2() },
    { 2636, 0, VECTOR2(1, 2), VECTOR2() },
    { 2686, 0, VECTOR2(2, 2), VECTOR2() },
    { 2737, 0, VECTOR2(3, 2), VECTOR2() },
    { 2785, 0, VECTOR2(3, 3), VECTOR2() },
    { 2814, 0, VECTOR2(2, 3), VECTOR2() },

    { 2838, 0, VECTOR2(2, 2), VECTOR2() },
    { 2888, 0, VECTOR2(3, 2), VECTOR2() },
    { 2938, 0, VECTOR2(3, 1), VECTOR2() },
    { 2987, 0, VECTOR2(3, 0), VECTOR2() },
    { 3036, 1, VECTOR2(2, 0), VECTOR2(-1,0) },
    { 3062, 1, VECTOR2(3, 0), VECTOR2(1,0) },
    { 3087, 0, VECTOR2(3, 1), VECTOR2() },
    { 3135, 0, VECTOR2(2, 1), VECTOR2() },
    { 3185, 0, VECTOR2(1, 1), VECTOR2() },
    { 3210, 0, VECTOR2(0, 1), VECTOR2() },
    { 3235, 0, VECTOR2(0, 2), VECTOR2() },
    { 3259, 0, VECTOR2(1, 2), VECTOR2() },
    { 3284, 0, VECTOR2(2, 2), VECTOR2() },
    { 3335, 0, VECTOR2(3, 3), VECTOR2() },
    { 3357, 0, VECTOR2(2, 3), VECTOR2() },
    { 3384, 0, VECTOR2(1, 3), VECTOR2() },
    { 3395, 0, VECTOR2(1, 3), VECTOR2() },
    { 3412, 0, VECTOR2(0, 3), VECTOR2() },
    { 3423, 0, VECTOR2(0, 3), VECTOR2() },
    { 3436, 0, VECTOR2(0, 2), VECTOR2() },
    { 3457, 0, VECTOR2(0, 2), VECTOR2() },
    { 3484, 0, VECTOR2(1, 2), VECTOR2() },
    { 3509, 0, VECTOR2(1, 2), VECTOR2() },
    { 3534, 0, VECTOR2(2, 2), VECTOR2() },
    { 3560, 0, VECTOR2(2, 2), VECTOR2() },
    { 3584, 0, VECTOR2(2, 1), VECTOR2() },
    { 3607, 0, VECTOR2(1, 1), VECTOR2() },
    { 3632 - 5, 1, VECTOR2(1, 0), VECTOR2(0,-1) },
    { 3684, 0, VECTOR2(0, 0), VECTOR2() },
    { 3735, 0, VECTOR2(0, 0), VECTOR2() },
    { 3757, 0, VECTOR2(0, 0), VECTOR2() },
    { 3779, 2, VECTOR2(1, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 3779, 2, VECTOR2(2, 0), VECTOR2(3,0), VECTOR2(1,0) },
    { 3779, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(1,0) },

    { 3829, 0, VECTOR2(3, 0), VECTOR2() },
    { 3853, 0, VECTOR2(3, 0), VECTOR2() },

    { 3881, 2, VECTOR2(2, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 3881, 2, VECTOR2(1, 0), VECTOR2(0,0), VECTOR2(-1,0) },
    { 3881, 2, VECTOR2(0, 0), VECTOR2(0,0), VECTOR2(-1,0) },

    { 3934, 0, VECTOR2(0, 0), VECTOR2() },
    { 3978 - 5, 1, VECTOR2(1, 0), VECTOR2(1,0) },
    { 4004 - 5, 1, VECTOR2(2, 0), VECTOR2(1,0) },
    { 4029 - 5, 1, VECTOR2(3, 0), VECTOR2(1,0) },




    { 4080, 0, VECTOR2(2, 0), VECTOR2() },

    { 4130 - 5, 1, VECTOR2(3, 0), VECTOR2(1,0) },
    { 4154 - 5, 1, VECTOR2(3, 1), VECTOR2(0,1) },
    { 4180 - 5, 1, VECTOR2(3, 2), VECTOR2(0,1) },

    { 4231 - 5, 1, VECTOR2(3, 3), VECTOR2(0,1) },
    { 4253 - 5, 1, VECTOR2(2, 3), VECTOR2(-1,0) },
    { 4279 - 5, 1, VECTOR2(1, 3), VECTOR2(-1,0) },

    { 4328, 0, VECTOR2(1, 3), VECTOR2() },
    { 4353, 0, VECTOR2(1, 2), VECTOR2() },
    { 4378, 0, VECTOR2(1, 1), VECTOR2() },
    { 4402, 0, VECTOR2(1, 0), VECTOR2() },
    { 4429, 0, VECTOR2(1, 1), VECTOR2() },
    { 4454, 0, VECTOR2(1, 2), VECTOR2() },
    { 4476, 0, VECTOR2(1, 3), VECTOR2() },

    { 4525, 0, VECTOR2(2, 3), VECTOR2() },

    { 4576 - 5, 1, VECTOR2(2, 2), VECTOR2(0,-1) },
    { 4601 - 5, 1, VECTOR2(2, 1), VECTOR2(0,-1) },
    { 4627 - 5, 1, VECTOR2(2, 0), VECTOR2(0,-1) },

    { 4675, 0, VECTOR2(1, 0), VECTOR2() },
    { 4701, 0, VECTOR2(2, 0), VECTOR2() },
    { 4725, 0, VECTOR2(3, 0), VECTOR2() },
    { 4749, 0, VECTOR2(2, 0), VECTOR2() },
    { 4776, 0, VECTOR2(1, 0), VECTOR2() },
    { 4799, 0, VECTOR2(0, 0), VECTOR2() },


    { 4824 - 5, 1, VECTOR2(1, 0), VECTOR2(1,0) },
    { 4837 - 5, 1, VECTOR2(2, 0), VECTOR2(1,0) },
    { 4851 - 5, 1, VECTOR2(3, 0), VECTOR2(1,0) },




    { 4875, 0, VECTOR2(2, 1), VECTOR2() },

    { 4926 - 5, 1, VECTOR2(2, 0), VECTOR2(0,-1) },
    { 4950 - 5, 1, VECTOR2(2, 1), VECTOR2(0,1) },
    { 4974 - 5, 1, VECTOR2(2, 2), VECTOR2(0,1) },

    { 5022 - 5, 1, VECTOR2(3, 2), VECTOR2(1,0) },
    { 5047 - 5, 1, VECTOR2(3, 1), VECTOR2(0,-1) },
    { 5074 - 5, 1, VECTOR2(3, 0), VECTOR2(0,-1) },

    { 5122, 0, VECTOR2(3, 0), VECTOR2() },
    { 5148, 0, VECTOR2(3, 1), VECTOR2() },
    { 5173, 0, VECTOR2(3, 2), VECTOR2() },
    { 5197, 0, VECTOR2(3, 3), VECTOR2() },
    { 5222, 0, VECTOR2(3, 2), VECTOR2() },
    { 5248, 0, VECTOR2(3, 1), VECTOR2() },
    { 5272, 0, VECTOR2(3, 0), VECTOR2() },


    { 5319, 0, VECTOR2(2, 0), VECTOR2() },

    { 5371, 0, VECTOR2(2, 0), VECTOR2() },
    { 5394, 0, VECTOR2(2, 1), VECTOR2() },
    { 5420, 0, VECTOR2(2, 0), VECTOR2() },
    { 5445, 0, VECTOR2(1, 0), VECTOR2() },
    { 5469, 0, VECTOR2(0, 0), VECTOR2() },

    { 5519, 0, VECTOR2(0, 0), VECTOR2() },
    { 5544, 0, VECTOR2(1, 1), VECTOR2() },
    { 5569, 0, VECTOR2(2, 2), VECTOR2() },

    { 5620, 0, VECTOR2(2, 2), VECTOR2() },
    { 5645, 0, VECTOR2(3, 3), VECTOR2() },
    { 5667, 2, VECTOR2(3, 2), VECTOR2(3,0), VECTOR2(0,-1) },
    { 5667, 2, VECTOR2(3, 1), VECTOR2(3,0), VECTOR2(0,-1) },
    { 5667, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(0,-1) },

};

int note_count;

void nadenna_eazy_game_init()
{
    /*===== initialization =====*/
    nadenna_eazy_game_state = 0;
    music_timer = 0;
}

void nadenna_eazy_game_deinit()
{
    
}

void nadenna_eazy_game_update()
{
    switch (nadenna_eazy_game_state)
    {
    case 0:
        /*===== initialization =====*/

        nadenna_eazy_game_state += 1;
        note_count = sizeof(notes) / sizeof(Note);


        /* fallthrough */

    case 1:
        /*===== parameter setting =====*/

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::load(MUSIC_NADE, L"./Data/Musics/263269133.wav", 0.2f);

        music::play(MUSIC_NADE);

        grid_y = 0;
        grid_x = 0;

        nadenna_eazy_game_state += 1;
        fade_state = FADE_OUT_START;

        /* fallthrough */

    case 2:
        /*===== normal time =====*/

        if (fade_state == FADE_IN) fade_in();
        if (fade_state == FADE_OUT_START) fade_out();

        debug::setString("perfect:%i", result_note.perfect);
        debug::setString("good:%i", result_note.good);
        debug::setString("miss:%i", result_note.miss);
        debug::setString("max_score:%i", result_note.score);
        debug::setString("max_combo:%i", result_note.combo);

        music::update();

        player_update(true, true);

        for (int i = 0; i < note_count; i++)
        {
            if (music_timer >= notes[i].time - 60 && music_timer <= notes[i].time + 60)
            {
                note_update(notes, note_count);
            }
        }
        if (music_timer == 5800)
        {
            if (fade_state == FADE_NONE)
            {
                fade_state = FADE_IN;
            }
        }
        if (fade_state == FADE_DONE)
        {
            result_tag = RESULT_TUTO;
            next_scene = SCENE_RESULT; // Switch to next scene
        }
        

        music_timer++;
    }
}


void nadenna_eazy_game_render()
{
    GameLib::clear(0.0f, 0.0f, 0.0f);

    for (int i = 0; i < note_count; i++)
    {
        if (!notes[i].hit && music_timer >= notes[i].time - 50)
        {
            draw_note(notes[i]);
        }
        else if (notes[i].hit && music_timer <= notes[i].time + 50)
        {
            draw_judge_effect(notes[i]); // 判定結果に応じた演出表示
        }
    }

    primitive::rect
    (
        player_x, player_y,
        player_size, player_size,
        0, 0,
        0,
        1, 1, 1, 0.7f
    );

    rank_rend(result_nade, result_note, IN_GAME);

    // 縦線（column lines）
    for (int i = 0; i <= 4; ++i)
    {
        float x = start_x + i * cell_size;
        primitive::line(x, start_y, x, start_y + grid_size, 0.7f);
    }

    // 横線（row lines）
    for (int i = 0; i <= 4; ++i)
    {
        float y = start_y + i * cell_size;
        primitive::line(start_x, y, start_x + grid_size, y, 0.7f);
    }

    primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, 0, 0, 0, 0, fade_alpha);
}