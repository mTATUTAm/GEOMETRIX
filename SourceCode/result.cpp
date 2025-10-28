#include "all.h"

int result_state = 0;
int result_timer = 0;

Sprite* result_button;

void result_init()
{

}
void result_deinit()
{
    music::unload(MUSIC_CRY);
	music::unload(MUSIC_NADE);
}
void result_update()
{
    static bool initialized = false;

    if (!initialized) {
        result_state = 0;
        result_timer = 0;
        load_judge_effect_images();
        initialized = true;
    }

    result_timer += 1;

    switch (result_state)
    {
    case 0:
        grid_x = 0;
        grid_y = 3;
        result_state = 1;
        break;

    case 1:
        fade_state = FADE_OUT_START;
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(MUSIC_TITLE, true);

        result_button = sprite_load(L"./Data/Images/title_button.png");

        result_state = 2;
        break;

    case 2:
        debug::setString("perfect:%i", result_note.perfect);
        debug::setString("good:%i", result_note.good);
        debug::setString("miss:%i", result_note.miss);
        debug::setString("max_score:%i", result_note.score);
        debug::setString("max_combo:%i", result_note.max_combo);

        player_update(true, false);



        if (grid_x == 3 && grid_y == 3)
        {
            if (TRG(0) & PAD_START && !fast_move)
            {
                if (fade_state == FADE_NONE)
                {
                    fade_state = FADE_IN;
                    music::play(SOUND_CONFIRM, false);
                }
            }
        }

        if (fade_state == FADE_OUT_START)
        {
            fade_out();
        }
        if (fade_state == FADE_IN)
        {
            fade_in();             // Start fade-in only once
        }
        if (fade_state == FADE_DONE)
        {
            next_scene = SCENE_TITLE; // Switch to next scene         
        }

        break;
    }
}


void result_render()
{
	GameLib::clear(0.0f, 0.0f, 0.0f);


	if (result_tag == RESULT_TUTO)
	{
		
	}

    rank_rend(result_tuto, result_note, IN_RESULT);

    sprite_render
    (
        result_button,
        1230, 810,
        1.0f, 1.0f,
        0, 0,
        270, 270,
        0, 0,
        0
    );

    primitive::rect
    (
        player_x,
        player_y,
        player_size, player_size,
        0, 0,
        0,
        1, 1, 1, 0.7f
    );

	// 縦線（column lines）
	for (int i = 0; i <= 4; ++i)
	{
		float x = start_x + i * cell_size;
		primitive::line(x, start_y + (3 * cell_size), x, start_y + grid_size, 0.7f);
	}

	// 横線（row lines）
	for (int i = 3; i <= 4; ++i)
	{
		float y = start_y + i * cell_size;
		primitive::line(start_x, y, start_x + grid_size, y, 0.7f);
	}

	primitive::rect
	(
		0, 0,
		SCREEN_W, SCREEN_H,
		0, 0,
		0,
		0, 0, 0, fade_alpha
	);
}