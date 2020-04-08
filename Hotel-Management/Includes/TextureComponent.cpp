#include "TextureComponent.h"

#include "WindowComponent.h"
#include "TextureManager.h"

TextureComponent::TextureComponent(SDL_Texture* texture,
	SDL_Rect& src, SDL_Rect& dst, ComponentType type) :
	_texture(texture), 
	TODO(ActionType::SKIP_FRAME)
{
	_type = type;
	srcRect = new SDL_Rect(src);
	dstRect = new SDL_Rect(dst);
}

TextureComponent::TextureComponent(SDL_Texture* texture,
	SDL_Rect* src, SDL_Rect* dst, ComponentType type) :
	_texture(texture), srcRect(src), dstRect(dst),
	TODO(ActionType::SKIP_FRAME)
{
	_type = type;
}


TextureComponent::TextureComponent(WindowComponent* owner, SDL_Rect& dst, ComponentType type, const std::string& location) :_owner(owner)
{
	SDL_Surface* loadedSurface = nullptr;

	loadedSurface = IMG_Load(location.c_str());

	if (!loadedSurface)
	{
		std::cout << "Error loading surface from location: " << location << std::endl;
		exit(-404);
	}
	else
	{
		_texture = SDL_CreateTextureFromSurface(_owner->getRenderer(), loadedSurface);
		if (!_texture)
		{
			std::cout << "Error creating texture from surface with location: " << location <<
				"SDL_Error: " << SDL_GetError() << std::endl;
			exit(-1);
		}
	}
	srcRect = new SDL_Rect();
	srcRect->w = loadedSurface->w;
	srcRect->h = loadedSurface->h;
	srcRect->y = 0;
	srcRect->x = 0;

	dstRect = new SDL_Rect(dst);
	TODO = ActionType::AWAYS_SHOWN;

	SDL_FreeSurface(loadedSurface);

}

TextureComponent::~TextureComponent()

{
	close();
}

void TextureComponent::init()
{
}

void TextureComponent::handleEvent(SDL_Event* e)
{
	
}

void TextureComponent::update(Component* sender)
{
	
	
}

void TextureComponent::draw(SDL_Renderer* renderer)
{
	if (TODO!= ActionType::SKIP_FRAME)
	{
		SDL_RenderCopy(renderer, _texture, srcRect, dstRect);
	}		
}

void TextureComponent::close()
{
	if (_texture)
	{
		SDL_DestroyTexture(_texture);
		_texture = nullptr;
	}
	
}

void TextureComponent::changeAction(ActionType action)
{
	TODO = action;
}

Component* TextureComponent::clone()
{
	TextureComponent* toRet = new TextureComponent();
	toRet->_texture = _texture;
	toRet->TODO = TODO;
	toRet->srcRect = srcRect;
	return toRet;
}
