#pragma once

#include "SDL_ttf.h"

#include "Component.h"

class ChangeableTextComponent : public Component
{
public:
	ChangeableTextComponent(TTF_Font* font, SDL_Color& color);

	virtual ~ChangeableTextComponent() = default;

	virtual void init()override;
	virtual void handleEvent(SDL_Event * e)override;
	virtual void update(Component * sender)override;
	virtual void draw(SDL_Renderer * renderer)override;
	virtual  ActionType getAction() override;
	virtual void changeAction(ActionType type) override;
	virtual void close()override;
	virtual ChangeableTextComponent* clone()override;

	virtual ComponentType getType() override;

private:
	SDL_Texture* _textTexture;
	SDL_Renderer* _renderer;
	TTF_Font* Font;
	SDL_Color _color;
	SDL_Rect dstRect;
	Component* _owner;
	ActionType TODO;
};

