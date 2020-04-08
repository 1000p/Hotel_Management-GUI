#include "ButtonComponent.h"
#include "WindowManager.h"

#include <iostream>



ButtonComponent::ButtonComponent(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dst,
	ComponentType type, WindowComponent* owner) :
	_texture(texture), _text(nullptr), _owner(owner),
	TODO(ActionType::SKIP_FRAME),
	srcRect(src), dstRect(dst), _pressed(false)
{
	_type = type;
	init();
	WindowManager::addComponent(owner, this, type);
}


void ButtonComponent::init()
{
	_position.y = dstRect.y;
	_position.x = dstRect.x;

	SDL_Rect clip{ srcRect.x, srcRect.y, srcRect.w, srcRect.h };

	for (int i = 0; i < 3; ++i)
	{
		_clips[i] = clip;
		clip.x += clip.w;
	}	
}

void ButtonComponent::handleEvent(SDL_Event* e)
{
	if (TODO != ActionType::UNACTIVATED)
	{
		if (e->type == SDL_MOUSEMOTION ||
			e->type == SDL_MOUSEBUTTONDOWN ||
			e->type == SDL_MOUSEBUTTONUP)
		{
			bool isInside = true;

			//COULD CAUSE POTENTIAL BUGS !!!!!!!!!!!!
			/*if (_pressed && e->type == SDL_MOUSEBUTTONUP)
			{
				_pressed = false;
			}*/

			Uint32 id = e->window.windowID;
			if (_owner->getID() != id)
			{
				TODO = ActionType::IDLE;
				srcRect = _clips[0];
				return;
			}

			int x, y;
			SDL_GetMouseState(&x, &y);




			//Left of the button
			if (x < _position.x)
			{
				isInside = false;
			}
			//Right of the button
			else if (x > _position.x + dstRect.w)
			{
				isInside = false;
			}
			//Above of the button
			else if (y > _position.y + dstRect.h)
			{
				isInside = false;
			}
			//Below of the button
			else if (y < _position.y)
			{
				isInside = false;
			}

			//Mouse is inside
			if (isInside)
			{
				switch (e->type)
				{

				case SDL_MOUSEMOTION:
					TODO = ActionType::IDLE;
					srcRect = _clips[1];
					std::cout << "MOUSE INSIDE" << std::endl;
					if (_text)
					{
						_text->changeAction(TODO);
					}
					
					break;
				case SDL_MOUSEBUTTONDOWN:
					srcRect = _clips[2];
					TODO = ActionType::IDLE;
					std::cout << "MOUSE B-DOWN" << std::endl;
					if (_text)
					{
						_text->changeAction(ActionType::CLICKED);
					}
					_pressed = true;
					break;
				case SDL_MOUSEBUTTONUP:
					srcRect = _clips[1];
					_pressed = false;
					std::cout << "MOUSE B-UP" << std::endl;
					TODO = ActionType::CLICKED;
					if (_text)
					{
						_text->changeAction(ActionType::IDLE);
					}
					break;
				}
			}
			//Mouse is outside
			else
			{
				TODO = ActionType::IDLE;
				if (_text)
				{
					_text->changeAction(TODO);
				}
				
				srcRect = _clips[0];

			}

		}
	}

	
}

void ButtonComponent::update(Component* sender)
{
	if (TODO != ActionType::SKIP_FRAME)
	{
		
	}
	else
	{
		TODO = ActionType::SKIP_FRAME;
	}
}

void ButtonComponent::draw(SDL_Renderer* renderer)
{
	if (TODO != ActionType::SKIP_FRAME &&
		TODO != ActionType::UNACTIVATED)
	{
		SDL_RenderCopy(renderer, _texture, &srcRect, &dstRect);
		if (_text)
		{			
			_text->draw(renderer);			
		}
	}
}

void ButtonComponent::close()
{
}

inline ActionType ButtonComponent::getAction()
{
	return  TODO;
}

void ButtonComponent::changeAction(ActionType action)
{
	TODO = action;
}

Component* ButtonComponent::clone()
{
	return this;
}

ActionType ButtonComponent::getTODO()
{
	return TODO;
}

void ButtonComponent::setText(const std::string& text, SDL_Color& color, TTF_Font* font, SDL_Point& displacementOnPressed)
{
	_text = new TextComponent(text, color, font, displacementOnPressed, dstRect, this);
}

ButtonComponent::ButtonComponent(SDL_Rect& src, SDL_Rect& dst,ComponentType type,
	WindowComponent* owner) :
	_texture(nullptr), _owner(owner), _text(nullptr), srcRect(src), dstRect(dst),
	TODO(ActionType::AWAYS_SHOWN),  
	_pressed(false)
{
	_type = type;
	init();
}

