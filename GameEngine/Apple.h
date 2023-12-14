#pragma once
#include <string>

#include "GameObject.h"

class Apple : public GameObject
{
public:
    int x = 20;
    int y = 20;

    int w = 20;
    int h = 20;

    float timer = 0;

    const char* imagePath = "img/apple.png";
    SDL_Surface* loadedSurface;
    SDL_Texture* appleTexture;

    void Start(SDL_Renderer* renderer) override;

    void Update(float deltaTime) override;
    
    void Render(SDL_Renderer* renderer) override;
};
