#pragma once
#include <SDL.h>
#include <iostream>

class GameObjects
{
public:
	float dx, dy;

	void updatePos();
	void collisionDetection(GameObjects& wall);
	// Draws image textures
	void drawImage(SDL_Renderer* renderer);
	// Draws with rects
	void draw(SDL_Renderer* renderer);
	int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2);
	
	// Constructor
	GameObjects(int x, int y, int dx, int dy, int w, int h)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->w = w;
		this->h = h;
	}
private:
	float x, y;
	int w, h;
};