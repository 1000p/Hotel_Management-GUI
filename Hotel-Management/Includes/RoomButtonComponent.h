#pragma once


#include "RoomWindowComponent.h"
#include "TextureManager.h"
#include "ButtonComponent.h"
#include "ProgramManager.h"

class RoomButtonComponent : public ButtonComponent
{
public:

	RoomButtonComponent(SDL_Renderer* renderer, SDL_Rect& src, SDL_Rect& dst, ComponentType type, 
		WindowComponent* owner) :
		ButtonComponent(src, dst,type, owner), _renderer(renderer), _window(nullptr)
	{
		//_window.init();
		init();
	}

	RoomButtonComponent(const std::string& surfaceLocation,
		SDL_Rect& src, SDL_Rect& dst, ComponentType type,
		WindowComponent* owner, std::string& title);


	RoomButtonComponent() = default;

	virtual void init() override;

	virtual void update(Component* sender) override;

	virtual void draw(SDL_Renderer* renderer) override;

	virtual RoomButtonComponent* clone() override;
	virtual  ActionType getAction() override;

	virtual void setText(TextComponent* other)
	{
		if (_text)
		{
			_text->close();
		}
		_text = new TextComponent(*other);
		if (!_text->hasText())
		{
			_text->changeText("Room " + std::to_string(_ID));
		}
		
	}

	void changeDestination(SDL_Rect& dst);

	void clear();

private:
	RoomWindowComponent* _window = nullptr;
	SDL_Renderer* _renderer;
	std::string _title;
	static int _ID;

};

