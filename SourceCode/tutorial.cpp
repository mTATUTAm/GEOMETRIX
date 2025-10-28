#include "all.h"


int tutorial_state;
int music_timer_tutorial;

int result_tag = 5;

Sprite* sentence_1;
Sprite* sentence_2;
Sprite* sentence_3;
Sprite* sentence_4;
Sprite* sentence_5;
Sprite* sentence_6;
Sprite* sentence_7;
Sprite* sentence_8;
Sprite* sentence_9;

Result_date result_tuto;

Note notes_tutorial[] = {
    { 627, 0, VECTOR2(1, 1), VECTOR2() },
    { 683, 0, VECTOR2(2, 1), VECTOR2() },
    { 736, 0, VECTOR2(3, 1), VECTOR2() },
    { 791, 0, VECTOR2(3, 2), VECTOR2() },
    { 846, 0, VECTOR2(2, 2), VECTOR2() },
    { 874, 0, VECTOR2(1, 2), VECTOR2() },
    { 901, 0, VECTOR2(0, 2), VECTOR2() },
    { 929, 0, VECTOR2(0, 1), VECTOR2() },

    { 1469, 1, VECTOR2(1, 1), VECTOR2(1,0) },
    { 1524, 1, VECTOR2(2, 1), VECTOR2(1,0) },
    { 1581, 1, VECTOR2(1, 1), VECTOR2(-1,0) },
    { 1636, 1, VECTOR2(0, 1), VECTOR2(-1,0) },
    { 1665, 1, VECTOR2(1, 1), VECTOR2(1,0) },
    { 1692, 1, VECTOR2(2, 1), VECTOR2(1,0) },
    { 1719, 1, VECTOR2(3, 1), VECTOR2(1,0) },
    { 1747+3, 1, VECTOR2(3, 2), VECTOR2(0,1) },
    { 1772+3, 1, VECTOR2(2, 2), VECTOR2(-1,0) },
    { 1799+3, 1, VECTOR2(1, 2), VECTOR2(-1,0) },
    { 1826+3 , 1, VECTOR2(0, 2), VECTOR2(-1,0) },

    { 2428, 0, VECTOR2(0, 0), VECTOR2() },
    { 2487, 0, VECTOR2(0, 0), VECTOR2() },
    { 2512, 0, VECTOR2(0, 0), VECTOR2() },

    { 2537, 2, VECTOR2(1, 0), VECTOR2(3,0), VECTOR2(1,0)},
    { 2537, 2, VECTOR2(2, 0), VECTOR2(3,0), VECTOR2(1,0)},
    { 2537, 2, VECTOR2(3, 0), VECTOR2(3,0), VECTOR2(1,0)},

    { 2651, 0, VECTOR2(3, 0), VECTOR2() },
    { 2706, 0, VECTOR2(3, 0), VECTOR2() },
    { 2733, 0, VECTOR2(3, 0), VECTOR2() },

    { 2760, 2, VECTOR2(3, 1), VECTOR2(3,3), VECTOR2(0,1) },
    { 2760, 2, VECTOR2(3, 2), VECTOR2(3,3), VECTOR2(0,1) },
    { 2760, 2, VECTOR2(3, 3), VECTOR2(3,3), VECTOR2(0,1) },

    { 2877, 0, VECTOR2(3, 3), VECTOR2() },
    { 2931, 0, VECTOR2(3, 3), VECTOR2() },
    { 2958, 0, VECTOR2(3, 3), VECTOR2() },

    { 2984, 2, VECTOR2(2, 3), VECTOR2(0,3), VECTOR2(-1,0)  },
    { 2984, 2, VECTOR2(1, 3), VECTOR2(0,3), VECTOR2(-1,0)  },
    { 2984, 2, VECTOR2(0, 3), VECTOR2(0,3), VECTOR2(-1,0)  },

    { 3103, 0, VECTOR2(0, 3), VECTOR2() },
    { 3158, 0, VECTOR2(0, 3), VECTOR2() },
    { 3181, 0, VECTOR2(0, 3), VECTOR2() },

    { 3208, 2, VECTOR2(0, 2), VECTOR2(0,0), VECTOR2(0,-1)   },
    { 3208, 2, VECTOR2(0, 1), VECTOR2(0,0), VECTOR2(0,-1)   },
    { 3208, 2, VECTOR2(0, 0), VECTOR2(0,0), VECTOR2(0,-1)   },

    { 2088, 0, VECTOR2(0, 2), VECTOR2() },
    { 2313, 0, VECTOR2(0, 1), VECTOR2() },

};

int note_count_tutorial;
float tuto_percent;

void tutorial_init()
{
    /*===== initialization =====*/
    tutorial_state = 0;
    music_timer_tutorial = 0;
}

void tutorial_deinit()
{
    safe_delete(sentence_1);
    safe_delete(sentence_2);
    safe_delete(sentence_3);
    safe_delete(sentence_4);
    safe_delete(sentence_5);
    safe_delete(sentence_6);
    safe_delete(sentence_7);
    safe_delete(sentence_8);
	safe_delete(sentence_9);

    music::stop(MUSIC_TITLE);
    music::unload(MUSIC_TITLE);
}

void tutorial_update()
{
    switch (tutorial_state)
    {
    case 0:
        /*===== initialization =====*/
        tutorial_state = 0;
        music_timer_tutorial = 0;


        tutorial_state += 1;
        note_count = sizeof(notes_tutorial) / sizeof(Note);
        /* fallthrough */

    case 1:
        /*===== parameter setting =====*/

        GameLib::setBlendMode(Blender::BS_ALPHA);

        sentence_1 = sprite_load(L"./Data/Images/GEOMETRIX (1).png");
		sentence_2 = sprite_load(L"./Data/Images/GEOMETRIX (2).png");
		sentence_3 = sprite_load(L"./Data/Images/GEOMETRIX (3).png");
		sentence_4 = sprite_load(L"./Data/Images/GEOMETRIX (4).png");
		sentence_5 = sprite_load(L"./Data/Images/GEOMETRIX (5).png");
		sentence_6 = sprite_load(L"./Data/Images/GEOMETRIX (6).png");
		sentence_7 = sprite_load(L"./Data/Images/GEOMETRIX (7).png");
		sentence_8 = sprite_load(L"./Data/Images/GEOMETRIX (8).png");
		sentence_9 = sprite_load(L"./Data/Images/GEOMETRIX (9).png");

        for (int i = 0; i < 45; i++) {
            notes_tutorial[i].hit = false;
        }

        music::load(MUSIC_TITLE, L"./Data/Musics/かめりあ(Camellia) - yesterday.wav", 0.1f);
		music::play(MUSIC_TITLE, true);

        grid_y = 1;
        grid_x = 1;

		music_timer = 0;
        tutorial_state += 1;
        fade_state = FADE_OUT_START;

        result_note = Result_date{};

        result_tuto.max_score = 45000;

        /* fallthrough */

    case 2:
        /*===== normal time =====*/

        debug::setString("perfect:%i", result_note.perfect);
        debug::setString("good:%i", result_note.good);
        debug::setString("miss:%i", result_note.miss);
        debug::setString("max_score:%i", result_note.score);
        debug::setString("max_combo:%i", result_note.combo);

        music::update();

        player_update(true, true);

        for (int i = 0; i < note_count; i++)
        {
            if (music_timer >= notes_tutorial[i].time - 60 && music_timer <= notes_tutorial[i].time + 60)
            {
                note_update(notes_tutorial, note_count);
            }
        }

        
        if (grid_x == 3 && grid_y == 3)
        {
            if (TRG(0) & PAD_START && !fast_move)
            {
				next_scene = SCENE_RESULT; // Switch to result scene
            }
        }

        music_timer++;

        if (music_timer == 3450)
        {
            if (fade_state == FADE_NONE)
            {
                fade_state = FADE_IN;
            }
        }
    }

    if (fade_state == FADE_IN)
    {
        fade_in();             // Start fade-in only once
    }
    if (fade_state == FADE_OUT_START)
    {
        fade_out();
    }

    // After fade-in is done
    if (fade_state == FADE_DONE)
    {
		result_tag = RESULT_TUTO;
        next_scene = SCENE_RESULT; // Switch to next scene
    }
}


void tutorial_render()
{
    GameLib::clear(0.0f, 0.0f, 0.0f);

    rank_rend(result_tuto, result_note, IN_GAME);

    for (int i = 0; i < note_count; i++)
    {
        if (!notes_tutorial[i].hit && music_timer >= notes_tutorial[i].time - 50)
        {
            draw_note(notes_tutorial[i]);
        }
        else if (notes_tutorial[i].hit && music_timer <= notes_tutorial[i].time + 50)
        {
            draw_judge_effect(notes_tutorial[i]); // 判定結果に応じた演出表示
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

    if (music_timer == 100) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 100 && music_timer <= 300)
    {
        sprite_render
        (
            sentence_1,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
    }
    if (music_timer == 300) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 300 && music_timer <= 500)
    {
        sprite_render
        (
            sentence_2,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
	}
    if (music_timer == 500) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 500 && music_timer <= 1000)
    {
        sprite_render
        (
            sentence_3,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
	}

    if (music_timer == 1100) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 1100 && music_timer <= 1300)
    {
        sprite_render
        (
            sentence_4,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
    }
    if (music_timer == 1300) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 1300 && music_timer <= 1800)
    {
        sprite_render
        (
            sentence_5,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
    }

    if (music_timer == 1900) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 1900 && music_timer <= 2100)
    {
        sprite_render
        (
            sentence_6,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
    }
    if (music_timer == 2100) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 2100 && music_timer <= 2300)
    {
        sprite_render
        (
            sentence_7,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
    }
    if (music_timer == 2300) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 2300 && music_timer <= 2500)
    {
        sprite_render
        (
            sentence_8,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
    }

    if (music_timer == 3250) music::play(SOUND_CONFIRM, false);
    if (music_timer >= 3250)
    {
        sprite_render
        (
            sentence_9,
            420, 810,
            1.0f, 1.0f,
            0, 0,
            1080, 270,
            0, 0,
            0
        );
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