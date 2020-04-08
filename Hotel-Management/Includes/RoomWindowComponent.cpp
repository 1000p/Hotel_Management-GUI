#include <iostream>


#include "RoomWindowComponent.h"
#include "TextureComponent.h"
#include "TextureManager.h"
#include "WindowManager.h"
#include "RoomButtonComponent.h"

RoomWindowComponent::RoomWindowComponent(SDL_Window* window,
	SDL_Renderer* renderer, std::vector<std::pair<ComponentType, Component*>>& comps) :
	WindowComponent(window, renderer, comps), _owner(nullptr) {}

RoomWindowComponent::RoomWindowComponent(RoomButtonComponent* owner): _owner(owner)
{
	init();
}

RoomWindowComponent::RoomWindowComponent(ComponentType type)
{
	_type = type;	
}

RoomWindowComponent::RoomWindowComponent()
{

}

void RoomWindowComponent::init()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Init renderer and window
	window = SDL_CreateWindow("Room Window", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_HIDDEN);
	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//LINK this component with its ID
	WindowManager::linkWindowComponent(window, this);

	//Check proper init
	if (window == nullptr || renderer == nullptr)
	{
		std::cout << "Could not initialize room window/renderer. SDL_Error: " <<
			SDL_GetError() << std::endl;
		return;
	}

	//Set members class members
	_window = window;
	_renderer = renderer;
	_type = ComponentType::ROOM_WINDOW;
	_ID = SDL_GetWindowID(window);

	//Set renderer
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);

	//Window backdrop
	TextureComponent* backdrop = new TextureComponent(
		TextureManager::loadTexture(renderer, "Images/Main Window/Sidebar - Chalkboard.png"),
		nullptr, nullptr, ComponentType::ROOM_BACKDROP);

	backdrop->changeAction(ActionType::AWAYS_SHOWN);

	//Add to the window 
	_components.push_back(backdrop);
	_content[ComponentType::ROOM_BACKDROP].push_back( backdrop);
	
}

void RoomWindowComponent::close()
{
	_owner->clear();
	WindowComponent::close();
}

RoomWindowComponent* RoomWindowComponent::clone()
{
	return this;
}
