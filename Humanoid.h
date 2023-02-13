#pragma once
#include "GameObjects.h"

class Humanoid : public GameObjects
{
public:
	Humanoid(int x, int y, int dx, int dy, int w, int h) 
	: GameObjects(x, y, dx, dy, w, h)
	{
		return;
	}

	void movement();
private:
	int hp;
	bool alive;
};