#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst):
	_texture(texture), _action(nullptr),
	TODO(ActionType::SKIP_FRAME), srcRect(src), dstRect(dst), currentClip(0)
{
}

void SpriteComponent::init()
{
}

void SpriteComponent::handleEvent(SDL_Event* e)
{
}

void SpriteComponent::update(Component* sender)
{
	if (_action)
	{
		TODO = _action->perform();
		switch (TODO)
		{
		case ActionType::FILLSCREEN:
			break;

		case ActionType::CLICKED:

			break;
		default:

			break;
		}
	}
	else
	{
		TODO = ActionType::SKIP_FRAME;
	}
}

void SpriteComponent::draw(SDL_Renderer* renderer)
{
	if (TODO != ActionType::SKIP_FRAME)
	{
		SDL_RenderCopy(renderer, _texture, srcRect, dstRect);
	}
}

void SpriteComponent::close()
{
}

void SpriteComponent::changeAction(Action* action)
{
	if (_action)
	{
		delete _action;
	}
	_action = action;
}

Component* SpriteComponent::clone()
{
	return this;
}
