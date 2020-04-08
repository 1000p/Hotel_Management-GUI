#pragma once
#include <string>
#include <iostream>

#include "SDL_ttf.h"
#include "Component.h"


class TextComponent: public Component
{
public:

	TextComponent(const std::string& text, SDL_Color& color,
		TTF_Font* font, SDL_Point& displacementOnPressed, SDL_Rect& dst, Component* sender);

	virtual ~TextComponent() = default;

	virtual void init()override;
	virtual void handleEvent(SDL_Event* e)override;
	virtual void update(Component* sender)override;
	virtual void draw(SDL_Renderer* renderer)override;
	virtual  ActionType getAction() override;
	virtual void changeAction(ActionType type) override;
	virtual void close()override;
	virtual TextComponent* clone()override;

	virtual ComponentType getType() override
	{
		return _type;
	}

	void changeText(const std::string& text);

	void centerInRect(SDL_Rect& dst)
	{
		int disX = abs(_displacementOnPressed.x - dstRect.x);
		int disY = abs(_displacementOnPressed.y - dstRect.y);

		dstRect.w = static_cast<int>(dst.w * 0.5);
		dstRect.h = static_cast<int>(dst.h * 0.5);
		dstRect.x = dst.x + ((dst.w - dstRect.w) / 2);
		dstRect.y = dst.y + ((dst.h - dstRect.h) / 2);

		_displacementOnPressed = { disX + dstRect.x,
		disY + dstRect.y, dstRect.w, dstRect.h };
	}

	bool hasText()
	{
		return _textTexture;
	}

	void draw(SDL_Renderer* renderer, SDL_Rect& dst);

private:

	TextComponent() = default;

	SDL_Texture* _textTexture;
	SDL_Renderer* _renderer;
	TTF_Font* _font;
	SDL_Color _color;
	SDL_Rect dstRect;
	SDL_Rect _displacementOnPressed;
	Component* _owner;
	ActionType TODO;
};

