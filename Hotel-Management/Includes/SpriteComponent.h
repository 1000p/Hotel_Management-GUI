#pragma once

#include <vector>

#include "Component.h"
#include "Action.h"


class SpriteComponent : public Component
{
public:
	SpriteComponent(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst);

	virtual void init() = 0;
	virtual void handleEvent(SDL_Event* e) = 0;
	virtual void update(Component* sender) = 0;
	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void close() = 0;
	virtual void changeAction(Action* action) = 0;
	virtual Component* clone() override;

private:
	SDL_Texture* _texture;
	Action* _action;
	ActionType TODO;
	SDL_Rect* srcRect;
	SDL_Rect* dstRect;
	std::vector<SDL_Rect> clips;
	int currentClip;
};

