#include "GameObjects.h"

void GameObjects::drawImage(SDL_Renderer* renderer)
{
    SDL_Rect rect = { this->x, this->y, this->w, this->h };
    SDL_RenderCopy(renderer, this->texture, nullptr, &rect);

    SDL_Surface* surface = nullptr;
    surface = IMG_Load("");

    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void GameObjects::draw(SDL_Renderer* renderer)
{
	// Initializes a SDL rect with x,y,w,h values
	SDL_Rect rect = { this->x, this->y, this->w, this->h };
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	// Draws and fills the rect
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);
}

void GameObjects::updatePos()
{
	this->x += this->dx;
	this->y += this->dy;
}


void GameObjects::collisionDetection(GameObjects& wall)
{
    // Check for collision with ledges
    for (int i = 0; i < 100; i++)
    {
        float mw = this->w, mh = this->h;
        float mx = this->x, my = this->y;
        float bx = wall.x, by = wall.y, bw = wall.w, bh = wall.h;

        if (mx + mw / 2 > bx && mx + mw / 2 < bx + bw)
        {
            // Bumping our head?
            if (my < by + bh && my > by && this->dy < 0)
            {
                // Correct y
                this->y = by + bh;
                my = by + bh;

                // Bumped head, stop jump vel
                this->dy = 0;
            }
        }
        if (mx + mw > bx && mx < bx + bw)
        {
            // Landing on edge?
            if (my + mh > by && my < by && this->dy > 0)
            {
                // Correct y
                this->y = by - mh;
                my = by - mh;

                // Landed here, stop jump vel
                this->dy = 0;
            }
        }

        if (my + mh > by && my < by + bh)
        {
            // Hitting right edge
            if (mx < bx + bw && mx + mw > bx + bw && this->dx < 0)
            {
                // Correct x
                this->x = bx + bw;
                mx = bx + bw;

                this->dx = 0;
            }
            // Hitting left edge
            else if (mx + mw > bx && mx < bx && this->dx > 0)
            {
                // Correct x
                this->x = bx - mw;
                mx = bx - mw;

                this->dx = 0;
            }
        }
    }
}