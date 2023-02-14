#pragma once
#include <SDL.h>
#include "Humanoid.h"
#include "Renderer.h"
#include "GameObjects.h"

class GameState
{
public:
	Humanoid* player;
	GameObjects* stage;

	int time;

	// Methods
	void loadGame();
	bool processEvents(SDL_Window* window);
	void processTick();
	void endGame();

private:

};