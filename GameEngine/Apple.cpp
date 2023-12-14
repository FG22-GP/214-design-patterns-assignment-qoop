#include "Apple.h"

#include <SDL_image.h>
#include <SDL_render.h>


void Apple::Start(SDL_Renderer* renderer)
{
	loadedSurface = IMG_Load(imagePath);
	appleTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	rect.x = rand()%1024;
	rect.y = rand() % 500;
}

void Apple::Update(float deltaTime)
{
	rect.y += fallSpeed * deltaTime;

	if (rect.y >= 768 + rect.h)
	{
		exit(0);
	}
}

void Apple::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopyF(renderer, appleTexture, NULL, &rect);
}
