#include "GameState.h"

void GameState::loadGame()
{
	this->time = 0;
}

bool GameState::processEvents(SDL_Window* window)
{
	SDL_Event event;
	bool done = false;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
		{
			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				done = true;
			}
		}
		break;
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = true;
				break;
			}
			break;
		case SDL_QUIT:
			// Quit game
			done = 1;
		}
		break;
		}
	}

	player->movement();
	player->collisionDetection(*stage);
	player->updatePos();

	return done;
}

void GameState::processTick()
{
	this->time++;
	player->dy += player->g;
}

void GameState::endGame()
{
	this->player = nullptr;
	this->stage = nullptr;
}