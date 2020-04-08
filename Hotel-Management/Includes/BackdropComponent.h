#pragma once



#include "WindowComponent.h"

class BackdropComponent: public Component
{
public:
	BackdropComponent(std::string & surfaceLocation);

	virtual ~BackdropComponent() = default;

	virtual void init()override;
	virtual void handleEvent(SDL_Event * e)override;
	virtual void update(Component * sender)override;
	virtual void draw(SDL_Renderer * renderer)override;
	virtual  ActionType getAction() override;
	virtual void changeAction(ActionType type) override;
	virtual void close()override;
	virtual BackdropComponent* clone()override;

	virtual ComponentType getType() override;

private:
	SDL_Texture* _texture;
	WindowComponent* _owner;
	ActionType TODO;
};

