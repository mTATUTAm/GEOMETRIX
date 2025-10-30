#include "all.h"
//test



Sprite* sss_sprite;
Sprite* ss_sprite;
Sprite* s_sprite;
Sprite* a_sprite;
Sprite* b_sprite;
Sprite* c_sprite;


void rank_rend_init()
{
    sss_sprite = sprite_load(L"./Data/Images/sss.png");
	ss_sprite = sprite_load(L"./Data/Images/ss.png");
	s_sprite = sprite_load(L"./Data/Images/s.png");
	a_sprite = sprite_load(L"./Data/Images/a.png");
	b_sprite = sprite_load(L"./Data/Images/b.png");
	c_sprite = sprite_load(L"./Data/Images/c.png");
}


void rank_rend(Result_date& date, Result_date& note, int game_state)
{
   
    float date_percent = ((float)result_note.score / (float)date.max_score) * 100.0f;

    debug::setString("percent:%f", date_percent);

    if (game_state == IN_GAME)
    {
        if (date_percent == 100.0f)
        {
            sprite_render(sss_sprite, 0, 270, 0.5f, 0.5f, 0, 0, 270, 270, 0, 0, 0);
        }
        else if (date_percent >= 98.0f)
        {
            sprite_render(ss_sprite, 0, 270, 0.5f, 0.5f, 0, 0, 270, 270, 0, 0, 0);
        }
        else if (date_percent >= 95.0f)
        {
            sprite_render(s_sprite, 0, 270, 0.5f, 0.5f, 0, 0, 270, 270, 0, 0, 0);
        }
        else if (date_percent >= 90.0f)
        {
            sprite_render(a_sprite, 0, 270, 0.5f, 0.5f, 0, 0, 270, 270, 0, 0, 0);
        }
        else if (date_percent >= 80.0f)
        {
            sprite_render(b_sprite, 0, 270, 0.5f, 0.5f, 0, 0, 270, 270, 0, 0, 0);
        }
        else
        {
            sprite_render(c_sprite, 0, 270, 0.5f, 0.5f, 0, 0, 270, 270, 0, 0, 0);
        }
    }

    if (game_state == IN_RESULT)
    {
        if (date_percent == 100.0f)
        {
            sprite_render(sss_sprite, SCREEN_W / 2, SCREEN_H / 3, 2.0f, 2.0f, 0, 0, 270, 270, 135, 135, 0);
        }
        else if (date_percent >= 98.0f)
        {
            sprite_render(ss_sprite, SCREEN_W / 2, SCREEN_H / 3, 2.0f, 2.0f, 0, 0, 270, 270, 135, 135, 0);
        }
        else if (date_percent >= 95.0f)
        {
            sprite_render(s_sprite, SCREEN_W / 2, SCREEN_H / 3, 2.0f, 2.0f, 0, 0, 270, 270, 135, 135, 0);
        }
        else if (date_percent >= 90.0f)
        {
            sprite_render(a_sprite, SCREEN_W / 2, SCREEN_H / 3, 2.0f, 2.0f, 0, 0, 270, 270, 135, 135, 0);
        }
        else if (date_percent >= 80.0f)
        {
            sprite_render(b_sprite, SCREEN_W / 2, SCREEN_H / 3, 2.0f, 2.0f, 0, 0, 270, 270, 135, 135, 0);
        }
        else
        {
            sprite_render(c_sprite, SCREEN_W / 2, SCREEN_H / 3, 2.0f, 2.0f, 0, 0, 270, 270, 135, 135, 0);
        }
    }
}