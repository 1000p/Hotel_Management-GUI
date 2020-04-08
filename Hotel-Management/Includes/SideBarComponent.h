#pragma once

#include "TextureComponent.h"

class SideBarComponent : public TextureComponent
{
public:
	SideBarComponent(SDL_Texture* texture,
		SDL_Rect& src, SDL_Rect& dst, ComponentType type);

	SideBarComponent(SDL_Texture* texture,
		SDL_Rect* src, SDL_Rect* dst, ComponentType type);

	SDL_Rect getDimentions()
	{
		return *dstRect;
	}

	virtual Component* clone() override;

private:
	SDL_Rect _buttonArea;
};

