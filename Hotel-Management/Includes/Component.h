#pragma once
#include "SDL.h"

#include "ActionType.h"
#include "ComponentType.h"

class Component
{
public:
	virtual ~Component() = default;

	virtual void init() = 0;
	virtual void handleEvent(SDL_Event* e) = 0;
	virtual void update(Component* sender) = 0;
	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void close() = 0;
	virtual void changeAction(ActionType action) = 0;
	virtual  ActionType getAction()  = 0;
	virtual Component* clone() = 0;

	virtual ComponentType getType() = 0;

protected:
	ComponentType _type;
};

