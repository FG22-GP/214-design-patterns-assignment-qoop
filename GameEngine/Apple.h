#pragma once
#include <string>

#include "GameObject.h"

class Apple : public GameObject
{
public:

	SDL_FRect rect{ 20,20,20,20 };

	float fallSpeed = 30;//px/s

	const char* imagePath = "img/apple.png";
	SDL_Surface* loadedSurface;
	SDL_Texture* appleTexture;

	void Start(SDL_Renderer* renderer) override;

	void Update(float deltaTime) override;
	
	void Render(SDL_Renderer* renderer) override;
};
