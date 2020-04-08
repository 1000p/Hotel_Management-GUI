#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "ActionType.h"
#include "Component.h"
#include "ComponentType.h"
//#include "FileSystem.h"

class WindowComponent: public Component
{
public:
	WindowComponent(SDL_Window* window, SDL_Renderer* renderer,
		std::vector<std::pair<ComponentType, Component*>>& comps);
	WindowComponent(SDL_Window* window, SDL_Renderer* renderer);

	virtual ~WindowComponent();

	virtual void init() override;
	virtual void handleEvent(SDL_Event* e)override;
	virtual void update(Component* sender) override;
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void close() override;
	virtual  ActionType getAction() override;
	virtual void changeAction(ActionType action)override;
	virtual Component* clone() override;

	void draw();
	Uint32 getID() { return _ID; }

	SDL_Renderer* getRenderer();

	std::list<Component*>& getComponents();

	std::unordered_map<ComponentType, std::vector<Component*>>& getContent();

protected:

	WindowComponent() = default;
	std::list<Component*> _components;
	std::unordered_map<ComponentType, std::vector<Component*>> _content;
	//FileSystem& fileSystem = FileSystem::getInstance();
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	ActionType TODO;
	Uint32 _ID;
};

