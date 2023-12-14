#include "Apple.h"

#include <SDL_image.h>
#include <SDL_render.h>


void Apple::Start(SDL_Renderer* renderer)
{
    loadedSurface = IMG_Load(imagePath);
    appleTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

    x = rand()%1024;
}

void Apple::Update(float deltaTime)
{
    timer += deltaTime;

    if (timer >= 1)
    {
        y++;
        timer -= 1;
    }
}

void Apple::Render(SDL_Renderer* renderer)
{
    SDL_Rect appleRectangle{x,y,w,h};

    SDL_RenderCopy(renderer, appleTexture, NULL, &appleRectangle);
}
