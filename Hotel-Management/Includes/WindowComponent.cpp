#include "WindowComponent.h"

#include "WindowManager.h"

#include <iostream>
WindowComponent::WindowComponent(SDL_Window* window, SDL_Renderer* renderer,
	std::vector<std::pair<ComponentType, Component*>>& comps)
: _window(window),_renderer(renderer)
{
	init();
	WindowManager::addComponents(this, comps);
	_ID = SDL_GetWindowID(window);
}

WindowComponent::WindowComponent(SDL_Window* window, SDL_Renderer* renderer)
	: _window(window), _renderer(renderer)
{
	init();
	_ID	 = SDL_GetWindowID(window);
}

WindowComponent::~WindowComponent()
{
	close();
}

void WindowComponent::init()
{	
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);
	_type = ComponentType::WINDOW;
	_ID = SDL_GetWindowID(_window);
}

void WindowComponent::handleEvent(SDL_Event* e)
{
	if (!_components.empty())
	{
		for (auto comp : _components)
		{
			comp->handleEvent(e);
		}
	}
}

void WindowComponent::update(Component* sender)
{
	for (auto comp : _components)
	{
		comp->update(this);
	}
}

void WindowComponent::draw(SDL_Renderer* renderer)
{
}

void WindowComponent::draw()
{
	SDL_RenderClear(_renderer);
	for (auto comp : _components)
	{
		comp->draw(_renderer);
	}
	SDL_RenderPresent(_renderer);
}

SDL_Renderer* WindowComponent::getRenderer()
{
	return _renderer;
}

std::list<Component*>& WindowComponent::getComponents()
{
	return _components;
}

std::unordered_map<ComponentType, std::vector<Component*>>& 
WindowComponent::getContent()
{
	return _content;
}

void WindowComponent::close()
{
	if (!_components.empty())
	{
		for (auto comp : _components)
		{
			comp->close();
		}
		_components.clear();
	}
	if (_window)
	{
		SDL_DestroyWindow(_window);
		_window = nullptr;
	}
	if (_renderer)
	{
		SDL_DestroyRenderer(_renderer);
		_renderer = nullptr;
	}
	
}

ActionType WindowComponent::getAction()
{
	return  TODO;
}

void WindowComponent::changeAction(ActionType action)
{
	TODO = action;
}

Component* WindowComponent::clone()
{
	return this;
}
