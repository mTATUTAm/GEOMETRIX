#include "all.h"


int title_state, title_timer;
int grid_x; 
int grid_y; 
int next_game_title;

Sprite* title;
Sprite* start_button;
Sprite* quit_button;
Sprite* tutorial_button;

//Sprite* SSS_sprite;
//Sprite* SS_sprite;
//Sprite* S_sprite;
//Sprite* A_sprite;
//Sprite* B_sprite;
//Sprite* C_sprite;


float start_x = 420.0f;     // 左端
float start_y = 0.0f;       // 上端
float grid_size = 1080.0f;  // 正方形のサイズ
float cell_size = grid_size / 4.0f; // = 270.0f


float player_size = 90.0f;


float player_x = start_x + grid_x * cell_size + (cell_size - player_size) / 2.0f;
float player_y = start_y + grid_y * cell_size + (cell_size - player_size) / 2.0f;

bool game_end = false;

void title_init()
{
	/*===== initialization =====*/
	title_state = 0;
	title_timer = 0;

	rank_rend_init();
	load_judge_effect_images();
}
void title_deinit()
{
	safe_delete(title);
	safe_delete(start_button);
	safe_delete(quit_button);

	music::stop(MUSIC_TITLE);
	music::unload(MUSIC_TITLE);
}
void title_update()
{
	title_timer += 1;

	switch (title_state)
	{
	case 0:
		/*===== initialization =====*/

		music::load(MUSIC_TITLE, L"./Data/Musics/かめりあ(Camellia) - yesterday.wav", 0.2f);

		music::load(SOUND_CONFIRM, L"./Data/Musics/1012.wav", 0.8f);
		music::load(SOUND_PERFECT, L"./Data/Musics/note_perfect.wav", 0.5f);
		music::load(SOUND_MOVE, L"./Data/Musics/8bitダメージ1.wav", 0.1f);
		music::load(SOUND_GOOD, L"./Data/Musics/note_good.wav", 0.5f);
		music::load(SOUND_MISS, L"./Data/Musics/note_miss.wav", 0.5f);
		music::load(SOUND_DASH, L"./Data/Musics/dash.wav", 0.3f);


		title = sprite_load(L"./Data/Images/スクリーンショット 2025-06-12 103726.png");
		start_button = sprite_load(L"./Data/Images/無題のプレゼンテーション (1).png");
		quit_button = sprite_load(L"./Data/Images/無題のプレゼンテーション (2).png");
		tutorial_button = sprite_load(L"./Data/Images/tutorial_button.png");

		/*SSS_sprite = sprite_load(L"./Data/Images/SSS.png");
		SS_sprite = sprite_load(L"./Data/Images/SS.png");
		S_sprite = sprite_load(L"./Data/Images/S.png");
		A_sprite = sprite_load(L"./Data/Images/A.png");
		B_sprite = sprite_load(L"./Data/Images/B.png");
		C_sprite = sprite_load(L"./Data/Images/C.png");*/


		title_state += 1;
		/* fallthrough */

	case 1:
		/*===== parameter setting =====*/

		fade_state = FADE_OUT_START;
		GameLib::setBlendMode(Blender::BS_ALPHA);

		grid_x = 0;
		grid_y = 3;
		next_game_title = 0;

		music::play(MUSIC_TITLE, true);

		title_state += 1;
		/* fallthrough */

	case 2:
		/*===== normal time =====*/

		player_update(true, false);

		if (fade_state == FADE_OUT_START)
		{
			fade_out();
		}

		

		// When PAD_SELECT is pressed
		if (grid_x == 1 && grid_y == 3)
		{
			if (TRG(0) & PAD_START && !fast_move)
			{
				if (fade_state == FADE_NONE)
				{
					fade_state = FADE_IN;
					next_game_title = 1;
					music::play(SOUND_CONFIRM, false);
				}
			}
		}

		if (grid_x == 2 && grid_y == 3)
		{
			if (TRG(0) & PAD_START && !fast_move)
			{
				if (fade_state == FADE_NONE)
				{
					fade_state = FADE_IN;
					music::play(SOUND_CONFIRM, false);
					game_end = true;
				}
			}
		}

		if (grid_x == 3 && grid_y == 3)
		{
			if (TRG(0) & PAD_START && !fast_move)
			{
				if (fade_state == FADE_NONE)
				{
					fade_state = FADE_IN;
					next_game_title = 2;
					music::play(SOUND_CONFIRM, false);
				}
			}
		}

		if (fade_state == FADE_IN)
		{
			fade_in();             // Start fade-in only once
		}
		if (fade_state == FADE_DONE)
		{
			if (game_end)
			{
				PostQuitMessage(0);
				break;
			}
			if (next_game_title == 1) next_scene = SCENE_GAME; // Switch to next scene
			if (next_game_title == 2) next_scene = SCENE_TUTORIAL; // Switch to next scene
		}
		break;

	default:
		break;
	}
}
void title_render()
{
	GameLib::clear(0.3f, 0.8f, 0.3f);



	// Heartbeat trigger timing
	const int beat_interval = 56;        // Frames between beats (2 beats per second for BPM128)
	const int pulse_duration = 45;       // How long the scale animation lasts

	float scale = 1.0f;                 // Base scale

	// Start pulsing after some time
	if (title_timer > 56)
	{
		int beat_phase = title_timer % beat_interval;

		if (beat_phase < pulse_duration)
		{
			// Scale up at beat, then return to normal
			float t = 1.0f - (float)beat_phase / pulse_duration;
			scale += 0.08f * t; // Max +0.08, decreasing over time
		}
	}

	// Draw background or logo with heartbeat effect
	sprite_render
	(
		title,
		SCREEN_W * 0.5f, SCREEN_H * 0.5f,
		scale, scale,
		0, 0,
		1920, 1080,
		1920 * 0.5f, 1080 * 0.5f,
		0
	);

	sprite_render
	(
		start_button,
		690, 810,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);

	sprite_render
	(
		quit_button,
		960, 810,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);

	sprite_render
	(
		tutorial_button,
		1230, 810,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);

	if (grid_x == 1 && grid_y == 3)
	{
		primitive::rect
		(
			690, 810,
			270, 270,
			0, 0,
			0,
			1, 0, 0, 0.3f
		);
	}

	if (grid_x == 2 && grid_y == 3)
	{
		primitive::rect
		(
			960, 810,
			270, 270,
			0, 0,
			0,
			1, 0, 0, 0.3f
		);
	}

	if (grid_x == 3 && grid_y == 3)
	{
		primitive::rect
		(
			1230, 810,
			270, 270,
			0, 0,
			0,
			1, 0, 0, 0.3f
		);

		debug::setString("perfect:%i good:%i miss:%i", result_tuto.perfect, result_tuto.good, result_tuto.miss);
		debug::setString("max_score:%i max_combo:%i", result_tuto.score, result_tuto.max_combo);
	}

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

	// Draw black fade overlay
	primitive::rect
	(
		0, 0,
		SCREEN_W, SCREEN_H,
		0, 0,
		0,
		0, 0, 0, fade_alpha
	);

}