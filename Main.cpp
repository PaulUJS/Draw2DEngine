#include <stdio.h>
#include <iostream>
#include <SDL.h>

#include "GameState.h"
#include "Renderer.h"
#include "Humanoid.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


int main(int argc, char* args[])
{
	GameState gameState;
	Renderer engineRenderer;
	Humanoid player(200, 200, 0, 0, 15, 15);
	GameObjects wall(400, 400, 0, 0, 60, 60);

	gameState.player = &player;
	gameState.wall = &wall;
	engineRenderer.player = &player;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	engineRenderer.renderer = renderer;

	bool done = false;
	gameState.loadGame();

	while (!done)
	{
		// Whenever a game ending event is returned game ends
		done = gameState.processEvents(window);
		engineRenderer.renderAll(wall);
	}

	// Cleanup
	window = nullptr;
	renderer = nullptr;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	gameState.endGame();

	SDL_Quit();
	return 0;
}