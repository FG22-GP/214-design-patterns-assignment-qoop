//Using SDL and standard IO
#include <array>
#include <ctime>
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>

#include "Apple.h"
#include "GameObject.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

std::vector<GameObject*> game_objects;

void Render(SDL_Renderer* renderer)
{
    for (auto game_object : game_objects)
    {
        game_object->Render(renderer);
    }
}

void Update(float deltaTime)
{
    for (auto game_object : game_objects)
    {
        game_object->Update(deltaTime);
    }
}

void Start(SDL_Renderer* renderer)
{
    for (auto game_object : game_objects)
    {
        game_object->Start(renderer);
    }
}

int main(int argc, char* args[])
{
    srand(time(0));

    Uint64 now = SDL_GetPerformanceCounter(), last = SDL_GetPerformanceCounter();
    float ticsPerSec = (float)SDL_GetPerformanceFrequency();

    //The window we'll be rendering to
    SDL_Window* window{};
    SDL_Renderer* renderer; // the window's rendering surface

    for (int i = 0; i < 20; ++i)
    {
        game_objects.push_back(new Apple());
    }

    // initialize SDL_Image for image loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    }

    // initialize SDL_ttf for font loading
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }

    //Start up SDL and create window
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create Window and Renderer
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window,
                                &renderer);
    if (!window)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"); // make the scaled rendering look smoother.
    SDL_RenderSetLogicalSize(renderer, 1024, 768);


    SDL_Event e;
    bool quit = false;

    Start(renderer);

    // while the user doesn't want to quit
    while (quit == false)
    {
        last = std::exchange(now, SDL_GetPerformanceCounter());
        float deltatime = (now - last) / ticsPerSec;


        // loop through all pending events from Windows (OS)
        while (SDL_PollEvent(&e))
        {
            // check, if it's an event we want to react to:
            switch (e.type)
            {
            case SDL_QUIT:
                {
                    quit = true;
                }
                break;
            }
        }

        // This is an example for how to check, whether keys are currently pressed:
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_LEFT])
        {
        }
        if (keystate[SDL_SCANCODE_RIGHT])
        {
        }

        Update(deltatime);

        // clear the screen
        SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
        SDL_RenderClear(renderer);

        Render(renderer);

        // present screen (switch buffers)
        SDL_RenderPresent(renderer);

        SDL_Delay(0); // can be used to wait for a certain amount of ms
    }

    return 0;
}
