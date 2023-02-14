#pragma once
#include "GameObjects.h"

class Humanoid : public GameObjects
{
public:
	Humanoid(float x, float y, float dx, float dy, float dxv, float dyv, int w, int h, float g)
	: GameObjects(x, y, dx, dy, dxv, dyv, w, h, g)
	{
		return;
	}

	void movement();
private:
	int hp;
	bool alive;
};