#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class GameObjects
{
public:
	float dx, dy, dxv, dyv;
	float x, y, g;
	int w, h;

	SDL_Texture* texture;

	void updatePos();
	void collisionDetection(GameObjects& wall);
	// Draws image textures
	void drawImage(SDL_Renderer* renderer);
	// Draws with rects
	void draw(SDL_Renderer* renderer);
	
	// Constructor
	GameObjects(float x, float y, float dx, float dy, float dxv, float dyv, int w, int h, float g)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dxv = dxv;
		this->dyv = dyv;
		this->dy = dy;
		this->w = w;
		this->h = h;
		this->g = g;
	}
private:
};