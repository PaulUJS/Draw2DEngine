#include "Renderer.h"

void Renderer::renderAll(GameObjects& stage)
{
	// Set drawing color blue
	SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);
	// Clear the screen to blue
	SDL_RenderClear(renderer);

	player->draw(renderer);
	stage.draw(renderer);
	SDL_RenderPresent(renderer);
}