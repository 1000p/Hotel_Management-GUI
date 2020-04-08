#pragma once
#include <string>

#include "SDL.h"

#include "Component.h"
#include "ActionType.h"
#include "WindowComponent.h"

class TextureComponent : public Component
{
public:
	TextureComponent(SDL_Texture* texture,
		SDL_Rect& src, SDL_Rect& dst, ComponentType type);
	TextureComponent(SDL_Texture* texture,
		SDL_Rect* src, SDL_Rect* dst, ComponentType type);

	TextureComponent(WindowComponent* owner, SDL_Rect& dst,
		ComponentType type, const std::string& location);

	TextureComponent() = default;

	virtual ~TextureComponent();

	virtual void init() override;
	virtual void handleEvent(SDL_Event* e)override;
	virtual void update(Component* sender) override;
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void close() override;
	virtual void changeAction(ActionType action);
	virtual  ActionType getAction() override
	{
		return  TODO;
	}
	virtual Component* clone() override;
	virtual ComponentType getType() override
	{
		return _type;
	}

protected:
	SDL_Texture* _texture;
	WindowComponent* _owner;
	ActionType TODO;
	SDL_Rect* srcRect;
	SDL_Rect* dstRect;
};

