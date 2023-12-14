#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:

	SDL_FRect rect{
		20,
		/*screen height*/768 - 120,
		100,
		100,
	};
	float speed = 200; //px/s

	const char* imagePath = "img/pikachu.png";
	SDL_Surface* loadedSurface;
	SDL_Texture* appleTexture;

	void Start(SDL_Renderer* renderer) override;

	void Update(float deltaTime) override;

	void Render(SDL_Renderer* renderer) override;
};
