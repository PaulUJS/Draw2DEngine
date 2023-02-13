#pragma once
#include <SDL.h>
#include "Humanoid.h"

class GameState
{
public:
	Humanoid* player;
	GameObjects* wall;

	// Methods
	void loadGame();
	bool processEvents(SDL_Window* window);
	void endGame();

private:

};