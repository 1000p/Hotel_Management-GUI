#include "Program.h"


#include "InitFunctions.h"
#include "TextureManager.h"
#include "TextureComponent.h"
#include "Component.h"
#include "WindowManager.h"
#include "ButtonComponent.h"



Program::Program() :
	_isRunning(false)
{	
}

//Initialize all SDL components
bool Program::init()
{
	bool success = true;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING)) //returns 0 on success
	{
		std::cout << "SDL components could not initialize! SDL_Error: " <<
			SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		WindowComponent* window = initMainWindow();
		if (window == nullptr)
		{
			std::cout << "PROBLEM WITH LOGIN SCREEN INIT" << std::endl;
			success = false;
		}
		else
		{
			addWindow(window->getID(), window);
			
		}
		
	}
	
	_isRunning = success;
	return success;
}

void Program::update()
{
	for (auto window : _windowsMap)
	{
		window.second->update(window.second);
	}
}

void Program::handleEvent()
{
	SDL_Event e;
	//std::unordered_map<Uint32, WindowComponent*>::iterator elementIt;

	SDL_PollEvent(&e);
	/*if (e.type == SDL_QUIT)
	{
		close();
		return;
	}
	*/
	for (auto window : _windowsMap)
	{		
		/*if (e.type == SDL_QUIT)
		{
			close();
			return;
		}*/
		if (!_windowsMap.empty())
		{
			window.second->handleEvent(&e);
			SDL_PollEvent(&e);
		}
		if (e.type == SDL_QUIT)
		{
			close();
			return;
		}
		
	}
}

void Program::draw()
{
	for (auto window : _windowsMap)
	{
		window.second->draw();
	}
}

void Program::close()
{
	for (auto window : _windowsMap)
	{
		window.second->close();
	}
	_windowsMap.clear();
	_isRunning = false;
}

void Program::addWindow(Uint32 ID, WindowComponent* toAdd)
{
	_windowsMap[ID] = toAdd;
}

void Program::removeWindow(Uint32 ID)
{
	WindowComponent* a = _windowsMap[ID];
	a->close();

	_windowsMap.erase(ID);
}




