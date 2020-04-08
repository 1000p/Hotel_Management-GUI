#pragma once

#include "WindowComponent.h"
//#include "RoomButtonComponent.h"

class RoomButtonComponent;

class RoomWindowComponent : public WindowComponent
{
public:
	RoomWindowComponent(SDL_Window* window, SDL_Renderer* renderer,
		std::vector<std::pair<ComponentType, Component*>>& comps);

	RoomWindowComponent(RoomButtonComponent* owner);
	RoomWindowComponent(ComponentType type);
	RoomWindowComponent();

	virtual ~RoomWindowComponent() = default;

	virtual void init() override;

	virtual void close() override;
	virtual RoomWindowComponent* clone() override;
	virtual ComponentType getType() override
	{
		return _type;
	}

	SDL_Window* getWindow()
	{
		return _window;
	}
	 
private:
	RoomButtonComponent* _owner;
};

