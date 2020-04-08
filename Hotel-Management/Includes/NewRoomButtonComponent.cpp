
#include "NewRoomButtonComponent.h"
#include "TextureManager.h"
#include "MainWindowComponent.h"
#include "RoomButtonComponent.h"

NewRoomButtonComponent::NewRoomButtonComponent(SDL_Texture* texture,
    SDL_Rect& src, SDL_Rect& dst, ComponentType type, WindowComponent* owner) :
    ButtonComponent(texture,src,dst,type, owner),
    _roomsPerRow(0), _roomsPerCol(0), _newRoomArea{ 0,0,0,0 }
{

}



void NewRoomButtonComponent::update(Component * sender)
{
    if (!_lastButton)
    {
        std::unordered_map<ComponentType, std::vector<Component*>>& content =
            _owner->getContent();
        SDL_Rect dimentions;
        if (content[ComponentType::ROOM_BUTTON].size() != 0)
        {
            _lastButton =
                static_cast<RoomButtonComponent*>
                (content[ComponentType::ROOM_BUTTON].back());

            dimentions = _lastButton->getDimentions();

          //  _roomsPerRow = _newRoomArea.w / dimentions.w;
           // _roomsPerCol = _newRoomArea.h / dimentions.h;
        }
        else 
        {
            FileSystem& fSystem = FileSystem::getInstance();
            _lastButton =
                static_cast<RoomButtonComponent*>
                (fSystem.getSpawner(ComponentType::ROOM_BUTTON));
            content[ComponentType::ROOM_BUTTON].push_back(_lastButton);
            std::list<Component*>& components = _owner->getComponents();
            components.push_back(_lastButton);
        }
       
    }

    ButtonComponent::update(sender);
     if (TODO == ActionType::CLICKED)
    {      
        if (_lastButton->getTODO() == ActionType::UNACTIVATED)
        {
            _lastButton->changeAction(ActionType::AWAYS_SHOWN);
            TODO = ActionType::IDLE;
            return;
        }

        SDL_Rect lastBdst = _lastButton->getDimentions();
        SDL_Rect dst{ lastBdst };

        if (lastBdst.x + (2 * lastBdst.w) <= _newRoomArea.w)
        {
            dst.x += lastBdst.w;
        }
        else if (lastBdst.y + (2 * lastBdst.h) <= _newRoomArea.h)
        {
            dst.x = _newRoomArea.x;
            dst.y += lastBdst.h;
        }
        else
        {
            std::cout << "NO MORE SPACE FOR NEW ROOMS" << std::endl;
            TODO = ActionType::IDLE;
            return;
        }

        TODO = ActionType::IDLE;
        RoomButtonComponent* toAdd = _lastButton->clone();
        toAdd->changeDestination(dst);
        WindowManager::addComponent(_owner, toAdd, toAdd->getType());
        toAdd->changeAction(ActionType::AWAYS_SHOWN);
        _lastButton = toAdd;
    }
}

void NewRoomButtonComponent::draw(SDL_Renderer* renderer)
{
    ButtonComponent::draw(renderer);
    if (_text)
    {
        _text->draw(renderer);
    }
}



void NewRoomButtonComponent::close()
{
    ////SHOULD IMPLEMENT LATER IN THE PROCESS WHEN PRODUCT IS WELL FINISHED
}

void NewRoomButtonComponent::changeAction(ActionType action)
{
    TODO = action;
}

Component* NewRoomButtonComponent::clone()
{
	return this;
}
