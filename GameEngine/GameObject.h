#pragma once
#include <SDL_render.h>

class GameObject
{
public:
	virtual void Update(float deltaTime){}
	virtual void Start(SDL_Renderer* renderer){}
	virtual void Render(SDL_Renderer* renderer){}
};

