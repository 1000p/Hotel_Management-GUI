#pragma once
#include <list>
#include <vector>
#include <string>

#include "Component.h"


class WindowManager
{
public:

	static void addComponent(WindowComponent* window,
		Component* toAdd, ComponentType type)
	{
		window->getComponents().push_back(toAdd);
		window->getContent()[type].push_back(toAdd);
	}

	static void addComponents
	(WindowComponent* window,
		std::vector<std::pair<ComponentType, Component*>>& toAdd)
	{
		std::list<Component*>& destination = window->getComponents();
		std::unordered_map<ComponentType, std::vector<Component*>>& content = window->getContent();
		for (auto comp : toAdd)
		{
			destination.push_back(comp.second);
			content[comp.first].push_back(comp.second);
		}
	}

	//static void addComponents(WindowComponent* window,
	//	std::vector<std::pair<ComponentType, Component*>>& toAdd)
	//{
	//	WindowManager::addComponents(window, toAdd);
	//}

	////It links SDL_Window ID to WindowComponent pointer
	static void linkWindowComponent(SDL_Window* window, WindowComponent* winComp)
	{
		const std::string ID = std::to_string(SDL_GetWindowID(window));
		SDL_SetWindowData(window, ID.c_str(), winComp);
	}

	static void* getWindowComponent(Uint32 id)
	{
		
		SDL_Window* window = SDL_GetWindowFromID(id);
		const std::string customData = std::to_string(id);
		if (customData.empty())
		{
			return nullptr;
		}
		return SDL_GetWindowData(window, customData.c_str());
	}
};

