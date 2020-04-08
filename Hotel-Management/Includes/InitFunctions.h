#pragma once
#include <vector>

#include "SDL.h"

#include "Component.h"
#include "TextureComponent.h"
#include "TextureManager.h"
#include "WindowComponent.h"
#include "ButtonComponent.h"
#include "WindowManager.h"
#include "NewRoomButtonComponent.h"
#include "MainWindowComponent.h"


bool initRenderer(const std::string& errorMessage, SDL_Renderer* renderer)
{
	return true;
}

bool initWindow(const std::string& errorMessage, SDL_Window* window)
{
	return true;
}

/*WindowComponent* initLoginWindow()
{
	//Login screen dimencions
	SDL_Rect src{ 0, 0, 100,100 };
	SDL_Rect dst{ 0,0,200,200 };

	//Login screen components
	std::vector<std::pair<ComponentType, Component*>> comps;

	//Login screen window and its renderer
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Init renderer and window
	window = SDL_CreateWindow("LOGIN", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 300, 400, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	//Check proper init
	if (window == nullptr || renderer == nullptr)
	{
		return nullptr;
	}

	//Create the components for the login screen
	//Login screen backdrop
	TextureComponent* backdrop = new TextureComponent(
		TextureManager::loadTexture(renderer, "Images/Login Screen/Backdrop.png"),
		nullptr, nullptr, ComponentType::BACKDROP);
	//Login screen submit button
	src = { 0,0,190,49 };
	dst = { 100,325, 100, 25 };
	SDL_Point position{ 100, 325 };
	ButtonComponent* button = new ButtonComponent(TextureManager::loadTexture(renderer, "Images/Login Screen/Grey-Button---spritesheet.png"),
		src, dst, position);
	
	//Change initial actions
	backdrop->changeAction(new AwaysShownAction);
	button->changeAction(new AwaysShownAction);
	//Add to components
	comps.push_back(std::make_pair(ComponentType::BACKDROP,backdrop));
	comps.push_back(std::make_pair(ComponentType::BUTTON, button));

	//The login screen
	WindowComponent* loginScreen = new WindowComponent{ window, renderer, comps };

	//Finally link id 
	WindowManager::linkWindowComponent(window, loginScreen);

	return loginScreen;
}*/

WindowComponent* initMainWindow()
{
	//Get program to able to get components from FileSystem
	//Program* program = ProgramManager::getProgram();

	////Login screen window and its renderer
	//SDL_Window* window = nullptr;
	//SDL_Renderer* renderer = nullptr;

	////Init renderer and window
	//window = SDL_CreateWindow("Hotel Management", SDL_WINDOWPOS_CENTERED,
	//	SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	//renderer = SDL_CreateRenderer(window, -1,
	//	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Check proper init
	/*if (window == nullptr || renderer == nullptr)
	{
		return nullptr;
	}*/

	MainWindowComponent* mainWindow = nullptr;
	mainWindow = new MainWindowComponent();

	return mainWindow;
}