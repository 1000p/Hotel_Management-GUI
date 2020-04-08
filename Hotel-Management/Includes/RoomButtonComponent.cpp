#include "RoomButtonComponent.h"

int RoomButtonComponent::_ID{ 0 };

RoomButtonComponent::RoomButtonComponent(const std::string& surfaceLocation,
	SDL_Rect& src, SDL_Rect& dst, ComponentType type,
	WindowComponent* owner, std::string& title): ButtonComponent(src,dst,type,owner), _title(title)
{
	_texture = TextureManager::loadTexture(owner->getRenderer(), surfaceLocation);
	++_ID;
}

 void RoomButtonComponent::init()
{
	_texture = TextureManager::loadTexture(_renderer,
		"Images/Login Screen/Grey-Button---spritesheet.png");
}

 inline void RoomButtonComponent::update(Component* sender)
 {
	 ButtonComponent::update(sender);
	 //_window.update(sender);
	 if (TODO == ActionType::CLICKED)
	 {
		 if (_window == nullptr)
		 {
			 std::cout << this->_title << std::endl;
			 _window = new RoomWindowComponent(this);
			 Program* program = ProgramManager::getProgram();
			 program->addWindow(_window->getID(), _window);
			 SDL_ShowWindow(_window->getWindow());
		 }
		 else
		 {
			 _window->close();
		 }
		 TODO = ActionType::IDLE;
	 }

 }


void RoomButtonComponent::draw(SDL_Renderer* renderer)
{
	ButtonComponent::draw(renderer);
	if (TODO == ActionType::CLICKED)
	{
		
	}
}

RoomButtonComponent* RoomButtonComponent::clone()
{
	RoomButtonComponent* toRet = new RoomButtonComponent();
	toRet->_texture = _texture;
	++_ID;
	toRet->_text = _text->clone();
	if (toRet->_title.empty())
	{
		toRet->_title = std::to_string(_ID);
		toRet->_text->changeText("Room " + toRet->_title);
	}	
	toRet->_owner = _owner;
	toRet->srcRect = srcRect;
	TODO = ActionType::AWAYS_SHOWN;
	toRet->_type = _type;
	toRet->_pressed = false;
	toRet->_clips[0] = _clips[0];
	toRet->_clips[1] = _clips[1];
	toRet->_clips[2] = _clips[2];

	return toRet;
}

ActionType RoomButtonComponent::getAction()
{
	return  TODO;
}

void RoomButtonComponent::changeDestination(SDL_Rect& dst)
{
	dstRect = dst;
	_position.x = dstRect.x;
	_position.y = dstRect.y;
	if (_text)
	{
		_text->centerInRect(dstRect);
	}
}

void RoomButtonComponent::clear()
{
	_window = nullptr;
}
