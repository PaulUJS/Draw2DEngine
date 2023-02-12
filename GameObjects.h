#pragma once

class GameObjects
{
public:
	void updatePos();
	void collisionDetection();

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
	float x, y, dx, dy;
	int w, h;
};