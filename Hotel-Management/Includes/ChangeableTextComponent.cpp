#include "ChangeableTextComponent.h"

ChangeableTextComponent::ChangeableTextComponent(TTF_Font* font, SDL_Color& color)
	: _textTexture(nullptr), _renderer(nullptr),
	Font(font), _color(color), _owner(nullptr),
	TODO(ActionType::SKIP_FRAME)
{
}

void ChangeableTextComponent::init()
{
}

void ChangeableTextComponent::handleEvent(SDL_Event* e)
{
}

void ChangeableTextComponent::update(Component* sender)
{
}

void ChangeableTextComponent::draw(SDL_Renderer* renderer)
{
}

ActionType ChangeableTextComponent::getAction()
{
	return ActionType();
}

void ChangeableTextComponent::changeAction(ActionType type)
{
}

void ChangeableTextComponent::close()
{
}

ChangeableTextComponent* ChangeableTextComponent::clone()
{
	return nullptr;
}

ComponentType ChangeableTextComponent::getType()
{
	return _type;
}
