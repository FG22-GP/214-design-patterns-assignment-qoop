#pragma once
#include <SDL_render.h>
#include <charconv>

class ScoreHandeler
{
public:
	int score = 0;
private:
	TTF_Font* font;

public:
	ScoreHandeler()
	{
		font = TTF_OpenFont("font/lazy.ttf", 100);
		if (font == NULL)
		{
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		}

	}


	int operator++(int)
	{
		return score++;
	}

	int operator--(int)
	{
		return score--;
	}

	void Draw(SDL_Renderer* renderer)
	{
		constexpr SDL_Color textColor = { 0xff, 0xff, 0xff };
		
		char buffer[10]{0};
		std::to_chars(buffer, buffer+9, score);
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, buffer , textColor);
		int textWidth, textHeight;
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
			return ;
		}
		else
		{
			// Create texture GPU-stored texture from surface pixels
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
			if (texture == NULL)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
				return;
			}
			// Get image dimensions
			textWidth = textSurface->w;
			textHeight = textSurface->h;


			SDL_Rect rect{ 10,20, textSurface->w ,textSurface->h };

			SDL_RenderCopy(renderer, texture, NULL, &rect);

			//Get rid of old loaded surface
			SDL_FreeSurface(textSurface);
			SDL_DestroyTexture(texture);
		}
	}
	
};