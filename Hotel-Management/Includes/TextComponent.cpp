#include "TextComponent.h"
#include "RoomButtonComponent.h"
#include "NewRoomButtonComponent.h"

TextComponent::TextComponent(const std::string& text, SDL_Color& color, TTF_Font* font, SDL_Point& displacementOnPressed,
	SDL_Rect& dst, Component* sender) :
	_font(font), _color(color), 
	_owner(sender)
{
	centerInRect(dst);

	ComponentType type = sender->getType();

	switch (type)
	{
	case ComponentType::UNDEFINED:
		break;
	case ComponentType::SIDEBAR:
		break;
	case ComponentType::MAIN_BACKDROP:
		break;
	case ComponentType::WINDOW:
		break;
	case ComponentType::BUTTON:
		break;
	case ComponentType::CREATE_ROOM_BUTTON:
	{
		NewRoomButtonComponent* owner = static_cast<NewRoomButtonComponent*>(sender);
		_renderer = owner->getOwner()->getRenderer();
		break;
	}
		
	case ComponentType::ROOM_BACKDROP:
		break;
	case ComponentType::ROOM_BUTTON:
	{
		RoomButtonComponent* owner = static_cast<RoomButtonComponent*>(sender);
		_renderer = owner->getOwner()->getRenderer();
		break;
	}

	case ComponentType::ROOM_WINDOW:
		break;
	default:
		break;
	}

	_displacementOnPressed = { displacementOnPressed.x + dstRect.x,
		displacementOnPressed.y + dstRect.y, dstRect.w, dstRect.h };

	if (text.empty())
	{
		return;
	}

	SDL_Surface* loadedSurface = TTF_RenderText_Solid(_font, text.c_str(), _color);
	if (!loadedSurface)
	{
		std::cout << "Failure to initialize text component with text: " << text << std::endl;
		exit(-404);
	}

	

	_textTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (!_textTexture)
	{
		std::cout << "Failed to render text component with text: " << text << std::endl;
		exit(-404);
	}

	

	SDL_FreeSurface(loadedSurface);

}

void TextComponent::init()
{
}

void TextComponent::handleEvent(SDL_Event* e)
{
}

void TextComponent::update(Component* sender)
{
}

void TextComponent::draw(SDL_Renderer* renderer)
{
	if (TODO != ActionType::SKIP_FRAME &&
		TODO != ActionType::UNACTIVATED)
	{
		if (_textTexture)
		{
			if (TODO == ActionType::CLICKED)
			{
				SDL_RenderCopy(renderer, _textTexture, nullptr, &_displacementOnPressed);
				//TODO = ActionType::IDLE;
			}
			else
			{
				SDL_RenderCopy(renderer, _textTexture, nullptr, &dstRect);
			}
			
		}
		
	}
	
}

ActionType TextComponent::getAction()
{
	return  TODO;
}

void TextComponent::changeAction(ActionType type)
{
	TODO = type;
}

void TextComponent::close()
{
}



TextComponent* TextComponent::clone()
{
	TextComponent* toRet = new TextComponent();
	toRet->_renderer = _renderer;
	toRet->_font = _font;
	toRet->_color = _color;
	toRet->dstRect = dstRect;
	toRet->_displacementOnPressed = _displacementOnPressed;
	toRet->TODO = TODO;
	return toRet;
}

void TextComponent::changeText(const std::string& text)
{

	SDL_Surface* loadedSurface = TTF_RenderText_Solid(_font, text.c_str(), _color);
	if (!loadedSurface)
	{
		std::cout << "Failure to initialize text component with text: " << text << std::endl;
		exit(-404);
	}
	_textTexture = nullptr;
	_textTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (!_textTexture)
	{
		std::cout << "Failed to render text component with text: " << text << std::endl;
		exit(-404);
	}
	SDL_FreeSurface(loadedSurface);
}

void TextComponent::draw(SDL_Renderer* renderer, SDL_Rect& dst)
{
	if (TODO != ActionType::SKIP_FRAME &&
		TODO != ActionType::UNACTIVATED)
	{
		SDL_RenderCopy(renderer, _textTexture, nullptr, &dst);
	}
}
