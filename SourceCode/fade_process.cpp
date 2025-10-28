#include "all.h"

int fade_state = FADE_NONE;
float fade_alpha = 1.0f;
float fade_speed = 0.02f;

void fade_in()
{
	fade_alpha += 0.02f;       // Increase alpha (darker)

	if (fade_alpha >= 1.0f)
	{
		fade_alpha = 1.0f;     // Limit alpha
		fade_state = FADE_DONE; // Fade-in completed
	}
}
void fade_out()
{
	fade_alpha -= 0.02f;       // Decrease alpha (lighter)

	if (fade_alpha <= 0.0f)
	{
		fade_alpha = 0.0f;     // Limit alpha
		fade_state = FADE_NONE; // Fade-out completed
	}
}