#pragma once

#include <vector>

#include "TextComponent.h"
#include "Component.h"
#include "WindowComponent.h"


class ButtonComponent :public Component
{
public:
	ButtonComponent(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dstm,ComponentType type,
		WindowComponent* owner);

	virtual void init()override;
	virtual void handleEvent(SDL_Event* e)override;
	virtual void update(Component* sender)override;
	virtual void draw(SDL_Renderer* renderer)override;
	virtual void close() override;
	virtual  ActionType getAction() override;
	virtual void changeAction(ActionType action) override;
	virtual Component* clone() override;
	virtual ComponentType getType() override
	{
		return _type;
	}

	ActionType getTODO();
	virtual SDL_Rect getDimentions()
	{
		return dstRect;
	}

	WindowComponent* getOwner()
	{
		return _owner;
	}

	virtual void setText(const std::string& text, SDL_Color& color, 
		TTF_Font* font, SDL_Point& displacementOnPressed);


	virtual void setText(TextComponent* other)
	{
		if (_text)
		{
			_text->close();
		}
		_text = new TextComponent(* other);
	}

	virtual TextComponent* getText()
	{
		return _text;
	}

protected:
	ButtonComponent(SDL_Rect& src, SDL_Rect& dst, ComponentType type,
		WindowComponent* owner);
	ButtonComponent() = default;

	SDL_Texture* _texture;
	WindowComponent* _owner;
	TextComponent* _text;
	SDL_Rect _clips[3];
	SDL_Rect srcRect;
	SDL_Rect dstRect; 
	SDL_Point _position;
	ActionType TODO;
	//ComponentType _type;
	bool _pressed;
	
};

