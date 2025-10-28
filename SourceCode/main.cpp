//include
#include "all.h"

int cur_scene = SCENE_NONE;
int next_scene = SCENE_TITLE;

//Writing the wWinMain function
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	//gamelib initialization
	GameLib::init(L"Test 1", SCREEN_W, SCREEN_H, true, 60.0);


	//game loop
	while (GameLib::gameLoop())
	{
		if(cur_scene != next_scene)
		{
			//Exit processing according to the current scene
			switch (cur_scene)
			{
			case SCENE_TITLE:
				title_deinit();
				break;

			case SCENE_GAME:
				game_deinit();
				break;

			case SCENE_EAZY:
				nadenna_eazy_game_deinit();
				break;

			case SCENE_CRY:
				crystallized_game_deinit();
				break;

			case SCENE_TUTORIAL:
				tutorial_deinit();
				break;

			case SCENE_RESULT:
				result_deinit();
				break;
			}

			//Initial setup process according to the next scene
			switch (next_scene)
			{
			case SCENE_TITLE:
				title_init();
				break;

			case SCENE_GAME:
				game_init();
				break;

			case SCENE_EAZY:
				nadenna_eazy_game_init();
				break;
			case SCENE_CRY:
				crystallized_game_init();
				break;
			case SCENE_TUTORIAL:
				tutorial_init();
				break;
			case SCENE_RESULT:
				result_init();
				break;
			}

			//next_scene becomes cur_scene
			cur_scene = next_scene;
		}

		//input update
		input::update();

		//title update and title render process according to the next scene
		switch (cur_scene)
		{
		case SCENE_TITLE:
			title_update();
			title_render();
			break;

		case SCENE_GAME:
			game_update();
			game_render();
			break;

		case SCENE_EAZY:
			nadenna_eazy_game_update();
			nadenna_eazy_game_render();
			break;

		case SCENE_CRY:
			crystallized_game_update();
			crystallized_game_render();
			break;

		case SCENE_TUTORIAL:
			tutorial_update();
			tutorial_render();
			break;
		case SCENE_RESULT:
			result_update();
			result_render();
			break;
		}

		//Display of debugging strings
		debug::display(1, 1, 1, 1, 1);
		//Screen display
		GameLib::present(1, 0);

	}
	//exit process accoeding to the current scene
	switch (cur_scene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;

	case SCENE_GAME:
		game_deinit();
		break;

	case SCENE_EAZY:
		nadenna_eazy_game_deinit();
		break;

	case SCENE_CRY:
		crystallized_game_deinit();
		break;

	case SCENE_TUTORIAL:
		tutorial_deinit();
		break;
	case SCENE_RESULT:
		result_deinit();
		break;
			
	}

	//Game library exit process
	GameLib::uninit();
	return 0;
}