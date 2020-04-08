#include "SideBarComponent.h"

 SideBarComponent::SideBarComponent(SDL_Texture* texture,
	 SDL_Rect& src, SDL_Rect& dst, ComponentType type) :
	TextureComponent(texture, src, dst, type), _buttonArea(dst)
{ }

 SideBarComponent::SideBarComponent(SDL_Texture* texture,
	 SDL_Rect* src, SDL_Rect* dst, ComponentType type) :
	TextureComponent(texture, src, dst, type), _buttonArea(*dst)
{ }

 Component* SideBarComponent::clone()
 {
	 return this;
 }
