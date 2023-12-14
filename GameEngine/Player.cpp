#include <SDL_image.h>
#include <SDL_render.h>

#include <cstdlib>
#include "Player.h"

void Player::Start(SDL_Renderer* renderer)
{
	loadedSurface = IMG_Load(imagePath);
	appleTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	rect.x = rand() % 1024;
}

void Player::Update(float deltaTime)
{
	// This is an example for how to check, whether keys are currently pressed:
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_LEFT])
	{
		rect.x -= speed * deltaTime;
	}
	if (keystate[SDL_SCANCODE_RIGHT])
	{
		rect.x += speed * deltaTime;
	}
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopyF(renderer, appleTexture, NULL, &rect);
}
