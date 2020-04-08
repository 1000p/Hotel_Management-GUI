#pragma once

//#include "ButtonComponent.h"
#include "MainWindowComponent.h"
#include "WindowManager.h"
#include "TextureManager.h"
#include "RoomButtonComponent.h"


class NewRoomButtonComponent : public ButtonComponent
{
public:
	NewRoomButtonComponent(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dst,
		ComponentType type, WindowComponent* owner);

	NewRoomButtonComponent(const std::string& surfaceLoc, SDL_Rect& src, SDL_Rect& dst,
		ComponentType type, MainWindowComponent* owner) : 
		ButtonComponent(src, dst, type, owner), _lastButton(nullptr),
		_newRoomArea{0,0,0,0},
		_roomsPerRow(0), _roomsPerCol(0)
	{
		_texture = TextureManager::loadTexture(owner->getRenderer(), surfaceLoc );
		_newRoomArea = owner->calculateRoomArea();
		SDL_Color color { 255,255,255 };
		SDL_Point displacement{ 0,0 };
		TTF_Font* font = TTF_OpenFont("Fonts/Raleway/Raleway-Bold.ttf", 26);
		_text = new TextComponent("Create new Room", color,font, displacement, dstRect, this);
		
	}


	virtual void update(Component* sender) override;
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void close() override;
	virtual void changeAction(ActionType action) ;
	virtual Component* clone() override;
	virtual ComponentType getType() override
	{
		return _type;
	}

	/*///*(Please keep in mind that I am publishing
	unfinished work and that this project was just for t
		he purpose of interacting with SDL 2.0, developing G
		UI application design skills and practicing my C++ skil
		ls, I really like the idea that I have in mind and I will
		be continuing the project with a different C++ framework 
		you can read more about that below)*///*/

private:
	RoomButtonComponent* _lastButton;
	int _roomsPerRow;
	int _roomsPerCol;
	TextComponent* _text;

	SDL_Rect _newRoomArea;
	
	
};

