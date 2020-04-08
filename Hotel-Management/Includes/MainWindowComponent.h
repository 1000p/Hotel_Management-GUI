#pragma once

#include "WindowComponent.h"
#include "SideBarComponent.h"
#include "ProgramManager.h"

class MainWindowComponent: public WindowComponent
{
public:
	MainWindowComponent(SDL_Window* window, SDL_Renderer* renderer,
		std::vector<std::pair<ComponentType, Component*>>& comps);

	MainWindowComponent(SDL_Window* window, SDL_Renderer* renderer);

	MainWindowComponent();

	virtual void handleEvent(SDL_Event* e) override;

	virtual Component* clone() override;

	virtual void close() override;
	virtual ComponentType getType() override
	{
		return _type;
	}

	SDL_Rect calculateRoomArea()
	{
		inerCalculateArea();
		return _newRoomArea;
	}



private:

	void addComponent(const std::string& type,
		const std::string& location, SDL_Rect& destination);

	void addRoomButtons(const std::string& fileLocation, ComponentType type,
		SDL_Rect& destination);

	void addSidebarButton(const std::string& fileLocation, ComponentType type,
		SDL_Rect& destination);

	void inerCalculateArea();

	SDL_Rect _newRoomArea;
	
	std::string _title;
};

