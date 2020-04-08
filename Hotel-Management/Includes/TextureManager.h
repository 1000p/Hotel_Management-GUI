#pragma once
#include <string>
#include <iostream>

#include "SDL_Image.h"

class TextureManager
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path)
	{
		SDL_Texture* finalTexture = nullptr;
		
		SDL_Surface* loadedSurface = nullptr;

		loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == nullptr)
		{
			std::cout << "Unable to load image with path: " << path << std::endl;
		}
		else
		{
			finalTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (finalTexture == nullptr)
			{
				std::cout << "Unable to create texture from path: " << path << std::endl;
			}
		}
		//Release memory
		SDL_FreeSurface(loadedSurface);

		return finalTexture;
	}

	static SDL_Texture* loadTexture(SDL_Surface* surface)
	{
		SDL_Texture* toRet = nullptr;
		//toRet = SDL
	}
	
	static void fillScreen(WindowComponent* receiver, SDL_Texture* texture)
	{
		SDL_RenderCopy(receiver->getRenderer(), texture, 0, 0);
		
	}


};