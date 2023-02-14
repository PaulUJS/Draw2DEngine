#include "Humanoid.h"

void Humanoid::movement()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_UP])
	{
		this->dx = 0;
		this->dy = 0;
		this->dy -= 1.5;
	}
	if (state[SDL_SCANCODE_DOWN])
	{
		this->dx = 0;
		this->dy = 0;
		this->dy += 1.5;
	}
	if (state[SDL_SCANCODE_LEFT])
	{
		this->dx = 0;
		this->dy = 0;
		this->dx -= 1.5;
	}
	if (state[SDL_SCANCODE_RIGHT])
	{
		this->dx = 0;
		this->dy = 0;
		this->dx += 1.5;
	}
}
