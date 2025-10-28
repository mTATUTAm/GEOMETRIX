#include "all.h"

int game_state, game_timer;
int next_game;

Result_date result_note;
Result_date result_nade;
Result_date result_cry; 


Sprite* crystallize_title;
Sprite* nadenna_taitle;
Sprite* title_button;
Sprite* eazy_button;
Sprite* normal_button;
Sprite* hard_button;
Sprite* preview_button;

void game_init()
{
	/*===== initialization =====*/
	game_state = 0;
	game_timer = 0;
	next_game = 0;

}
void game_deinit()
{
	safe_delete(crystallize_title);
	safe_delete(nadenna_taitle);
	safe_delete(title_button);
	safe_delete(eazy_button);
	safe_delete(normal_button);
	safe_delete(hard_button);
	safe_delete(preview_button);


	music::stop(MUSIC_CRY_INTRO);
	music::unload(MUSIC_CRY_INTRO);
	music::stop(MUSIC_NADE_INTRO);
	music::unload(MUSIC_NADE_INTRO);
}
void game_update()
{
	game_timer += 1;

	switch (game_state)
	{
	case 0:
		/*===== initialization =====*/

		game_state += 1;

		player_x = 0;
		player_y = 0;

            
		crystallize_title = sprite_load(L"./Data/Images/crystallize.png");
		nadenna_taitle = sprite_load(L"./Data/Images/nadenna.png");

		title_button = sprite_load(L"./Data/Images/title_button.png");
		eazy_button = sprite_load(L"./Data/Images/eazy_button.png");
		normal_button = sprite_load(L"./Data/Images/normal_button.png");
		hard_button = sprite_load(L"./Data/Images/hard_button.png");

		preview_button = sprite_load(L"./Data/Images/preview.png");

		/* fallthrough */

	case 1:
		/*===== parameter setting =====*/

		GameLib::setBlendMode(Blender::BS_ALPHA);

		grid_y = 0;
		grid_x = 0;

		music::load(MUSIC_CRY_INTRO, L"./Data/Musics/crystallized_intro.wav", 1.0f);
		music::load(MUSIC_NADE_INTRO, L"./Data/Musics/nadenna_intro.wav", 1.0f);

		//Loading and playing music
		

		game_state += 1;
		fade_state = FADE_OUT_START;

		/* fallthrough */

	case 2:
		/*===== normal time =====*/

		music::update();

        if (grid_y == 0 || grid_y == 2)  
            player_update(false, true);
        else if ((grid_x == 1 && grid_y == 1) ||
				 (grid_x == 2 && grid_y == 1) || 
				 (grid_x == 3 && grid_y == 1) ||
				 (grid_x == 1 && grid_y == 3) || 
				 (grid_x == 2 && grid_y == 3) || 
				 (grid_x == 3 && grid_y == 3))
            player_update(true, false);
		else 
			player_update(true, true);

        
		if (grid_y == 0)
		{
			debug::setString("grid_x:%i grid_y:%i", grid_x, grid_y);
			if (music::isInUse(MUSIC_CRY_INTRO))
			{
				music::stop(MUSIC_NADE_INTRO);
				if (music::getState(MUSIC_CRY_INTRO) == DirectX::STOPPED) music::play(MUSIC_CRY_INTRO, true);
			}
		}
		if (grid_y == 2)
		{
			debug::setString("grid_x:%i grid_y:%i", grid_x, grid_y);
			if (music::isInUse(MUSIC_NADE_INTRO))
			{
				music::stop(MUSIC_CRY_INTRO);
				if (music::getState(MUSIC_NADE_INTRO) == DirectX::STOPPED) music::play(MUSIC_NADE_INTRO, true);
			}
		}
		


		debug::setString("game_state:%i game_timer:%i", game_state, game_timer);
		debug::setString("grid_x:%i grid_y:%i", grid_x, grid_y);
		
		if (grid_x == 2 && grid_y == 1)
		{
			if (TRG(0) & PAD_START && !fast_move)
			{
				if (fade_state == FADE_NONE)
				{
					fade_state = FADE_IN;
					music::play(SOUND_CONFIRM, false);
					next_game = 3; // Set next game to 3 (cry)
				}
			}
		}
		if (grid_x == 0 && grid_y == 3)
		{
			if (TRG(0) & PAD_START && !fast_move)
			{
				if (fade_state == FADE_NONE)
				{
					fade_state = FADE_IN;
					music::play(SOUND_CONFIRM, false);
					next_game = 1; // Set next game to 1 (title)
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
					next_game = 2; // Set next game to 2 (eazy)
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
			if (next_game == 1) next_scene = SCENE_TITLE; // Switch to next scene
			else if (next_game == 2) next_scene = SCENE_EAZY; // Switch to Eazy scene
			else if (next_game == 3) next_scene = SCENE_CRY;
		}
		break;

	default:
		break;
	}
}
void game_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);

	sprite_render
	(
		title_button,
		420, 810,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);
	sprite_render
	(
		eazy_button,
		960, 810,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);
	/*sprite_render
	(
		normal_button,
		1230, 810,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);*/
	sprite_render
	(
		hard_button,
		960, 270,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);
	sprite_render
	(
		preview_button,
		420, 0,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
	);
	sprite_render
	(
		preview_button,
		420, 540,
		1.0f, 1.0f,
		0, 0,
		270, 270,
		0, 0,
		0
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

	sprite_render
	(
		crystallize_title,
		690, 0,
		1.0f, 1.0f,
		0, 0,
		810, 270,
		0, 0,
		0
	);

	sprite_render
	(
		nadenna_taitle,
		690, 540,
		1.0f, 1.0f,
		0, 0,
		810, 270,
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
			1, 0, 0, 0.1f
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
			1, 0, 0, 0.2f
		);
	}
	if (grid_x == 2 && grid_y == 1)
	{
		primitive::rect
		(
			960, 270,
			270, 270,
			0, 0,
			0,
			1, 0, 0, 0.3f
		);
	}
	if (grid_x == 0 && grid_y == 3)
	{
		primitive::rect
		(
			420, 810,
			270, 270,
			0, 0,
			0,
			1, 0, 0, 0.3f
		);
	}
	if (grid_x == 0 && grid_y == 0)
	{
		primitive::rect
		(
			420, 0,
			270, 270,
			0, 0,
			0,
			0.3f, 0.8f, 1.0f, 0.3f
		);
	}
	if (grid_x == 0 && grid_y == 2)
	{
		primitive::rect
		(
			420, 540,
			270, 270,
			0, 0,
			0,
			0.9f, 0.2f, 0.7f, 0.3f
		);
	}


	primitive::rect
	(
		player_x, player_y,
		player_size, player_size,
		0, 0,
		0,
		1, 1, 1, 0.7f
	);

	primitive::line(690, 0, 690, 270);
	primitive::line(1500, 0, 1500, 270);
	primitive::line(690, 0, 1500, 0);
	primitive::line(690, 270, 1500, 270);

	primitive::line(690, 540, 690, 810);
	primitive::line(1500, 540, 1500, 810);
	primitive::line(690, 540, 1500, 540);
	primitive::line(690, 810, 1500, 810);


	// Draw black rectangle with alpha
	primitive::rect(0, 0, SCREEN_W, SCREEN_H, 0, 0, 0, 0, 0, 0, fade_alpha);
}