#pragma once
#include <SDL.h>
#include "GameObjects.h"
#include "Humanoid.h"

class Renderer
{

public:
	SDL_Renderer* renderer;
	Humanoid* player;
	GameObjects* stage;

	void renderAll(GameObjects& stage);

private:

};