#pragma once
#include <list>
#include <iostream>

#include "FileSystem.h"	

//#include "SDL.h"
//#include "SDL_Image.h"
#include "SDL_ttf.h"
#include "WindowComponent.h"


class Program
{
public:
	Program();

	bool init();
	void update();
	void handleEvent();
	void draw();
	void close();
	bool isRunning()  { return !_windowsMap.empty(); }

	void addWindow(Uint32 ID, WindowComponent* toAdd);
	void removeWindow(Uint32 ID);


private:
	std::unordered_map<Uint32,WindowComponent*> _windowsMap;
	bool _isRunning;
	WindowComponent* _focusedWindow = nullptr;
};

 