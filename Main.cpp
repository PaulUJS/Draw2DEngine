#include <stdio.h>
#include <iostream>
#include <SDL.h>

#include "GameState.h"
#include "Renderer.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


int main(int argc, char* args[])
{
	GameState gameState;
	Renderer engineRenderer;

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
	}

	// Cleanup
	window = nullptr;
	renderer = nullptr;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	return 0;
}