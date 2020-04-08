#include <fstream>
#include <sstream>

#include "MainWindowComponent.h"
#include "RoomButtonComponent.h"
#include "NewRoomButtonComponent.h"



 MainWindowComponent::MainWindowComponent(SDL_Window* window, SDL_Renderer* renderer,
	 std::vector<std::pair<ComponentType, Component*>>& comps) :
	WindowComponent(window, renderer, comps) 
 {
	 inerCalculateArea();
 }

 MainWindowComponent::MainWindowComponent(SDL_Window* window, SDL_Renderer* renderer)
	 : WindowComponent(window,renderer)
 { }

 MainWindowComponent::MainWindowComponent(): _newRoomArea{0,0,0,0}
 {
	 std::ifstream mainWindow("Files/MainWindow.txt");
	 std::string line;

	 

	 std::ostringstream messenger;

	 std::string title;
	 std::pair<int, int> windowSize; //first = x ----- second = y
	 int amoundComponents{ 0 };

	 if (mainWindow.fail())
	 {
		 std::cout << "Could not open file at: Files/MainWindow.txt !" << std::endl;
		 exit(-404);
	 }
	 else
	 {
		 //Get title
		 getline(mainWindow, title);
		 _title = title;
		 //Get window size		 
		 mainWindow >> windowSize.first >> windowSize.second; mainWindow.ignore();

		 _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
			 SDL_WINDOWPOS_CENTERED, windowSize.first, windowSize.second, SDL_WINDOW_SHOWN);
		_renderer = SDL_CreateRenderer(_window, -1,
			 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		 //Get amound of components
		mainWindow >> amoundComponents; mainWindow.ignore();
		 
		 //Get components one by one 
		 std::string type;
		 std::string location;
		 SDL_Rect destination;

		 for (int comp = 0; comp < amoundComponents; ++comp)
		 {
			 mainWindow >> type; mainWindow.ignore();
			 getline(mainWindow, location, '#');
			 mainWindow >> destination.x >> destination.y
				 >> destination.w >> destination.h; mainWindow.ignore();
			 addComponent(type, location, destination);
		 }
	 }

	 WindowComponent::init();

 }

 void MainWindowComponent::handleEvent(SDL_Event * e)
 {
	 if (e->window.event == SDL_WINDOWEVENT_CLOSE)
	 {
		 Program* program = ProgramManager::getProgram();
		 program->removeWindow(e->window.windowID);
	 }
	 else
	 {
		 WindowComponent::handleEvent(e);
	 }

 }

 Component* MainWindowComponent::clone()
 {
	 return this;
 }

 void MainWindowComponent::close()
 {
	 WindowComponent::close();
	 //Program* program = ProgramManager::getProgram();
	
	 
 }

 void MainWindowComponent::addComponent(const std::string& type,
	 const std::string& location, SDL_Rect& destination)
 {
	 
	 ComponentType enumType;
	 if (type == "SIDEBAR")
	 {
		 enumType = ComponentType::SIDEBAR;
		 TextureComponent* sidebar =
			 new TextureComponent(this, destination, enumType, location);
		 _content[enumType].push_back(sidebar);
		 _components.push_back(sidebar);
		 sidebar->changeAction(ActionType::AWAYS_SHOWN);
	 }
	 else if (type == "MAIN_BACKDROP")
	 {
		 enumType = ComponentType::MAIN_BACKDROP;
		 TextureComponent* backdrop =
			 new TextureComponent(this, destination, enumType, location);
		 _content[enumType].push_back(backdrop);
		 _components.push_back(backdrop);
		 backdrop->changeAction(ActionType::AWAYS_SHOWN);
	 }
	 else if (type == "ROOM_BUTTON")
	 {
		 enumType = ComponentType::ROOM_BUTTON;
		 addRoomButtons(location, enumType, destination);
	 }
	 else if (type == "CREATE_ROOM_BUTTON")
	 {
		 enumType = ComponentType::CREATE_ROOM_BUTTON;
		 addSidebarButton(location, enumType, destination);
	 }
	 else
	 {
		 enumType = ComponentType::UNDEFINED;
		 std::cout << "ERROR LOADING COMPONENT FOR MAIN WINDOW. COMPONENT TYPE UNDEFINED RETURNED" << std::endl;
		 exit(-404);
	 }
 }

 void MainWindowComponent::addRoomButtons(const std::string& fileLocation,
	 ComponentType type, SDL_Rect& destination)
 {
	 std::ifstream roomButtons(fileLocation);

	 if (roomButtons.fail())
	 {
		 std::cout << "Error file at: "<<fileLocation<<" missing!" << std::endl;
		 exit(-404);
	 } 

	 std::string textureLoc;
	 getline(roomButtons, textureLoc, '#');

	 SDL_Rect src;
	 roomButtons >> src.x >> src.y >> src.w >> src.h; roomButtons.ignore();

	

	 int amoundOfRooms{ 0 };
	 roomButtons >> amoundOfRooms; roomButtons.ignore();

	 std::string ttfLoc;
	 getline(roomButtons, ttfLoc, '#');

	 TTF_Init();
	 TTF_Font* Font = TTF_OpenFont(ttfLoc.c_str(), 26);
	

	 if (!Font)
	 {
		 std::cout << "Error loading TTF font at :" << ttfLoc <<
			 "TTF_Error: " << TTF_GetError() << std::endl;
		 exit(-404);
	 }

	 SDL_Color textColor;
	 roomButtons >> textColor.r >> textColor.g >> textColor.b; roomButtons.ignore();

	 SDL_Point displacementOnPressed;
	 roomButtons >> displacementOnPressed.x >> displacementOnPressed.y;
	 roomButtons.ignore();
	 
	 std::string textOver;
	 getline(roomButtons, textOver);

	 RoomButtonComponent* button =
		 new RoomButtonComponent(textureLoc, src, destination, type, this, textOver);

	 TextComponent* text =
		 new TextComponent(textOver, textColor, Font,
			 displacementOnPressed, destination, button);

	 button->setText(text);
	 //button->setText(textOver, textColor, Font, displacementOnPressed);

	 if (amoundOfRooms > 0 && amoundOfRooms <= 5)
	 {
		 _content[type].reserve(5);
		 button->changeAction(ActionType::AWAYS_SHOWN);
	 }
	 else if (amoundOfRooms>5)
	 {
		 _content[type].reserve(amoundOfRooms);
		 button->changeAction(ActionType::AWAYS_SHOWN);
	 }
	 else 
	 {
		 button->changeAction(ActionType::UNACTIVATED);
		 FileSystem& fSystem = FileSystem::getInstance();
		 fSystem.addSpawner(type, button);
		 return;
	 }

	 SDL_Rect dst;
	 roomButtons >> dst.x >> dst.y >> dst.w >> dst.h; roomButtons.ignore();

	 _content[type].push_back(button);
	 _components.push_back(button);

	 

	 for (int room = 1; room < amoundOfRooms; ++room)
	 {
		 getline(roomButtons, textOver);
		 roomButtons >> dst.x >> dst.y >> dst.w >> dst.h; roomButtons.ignore();
		 RoomButtonComponent* nextB = button->clone();
		 nextB->changeDestination(dst);

		 nextB->getText()->changeText(textOver);

		 _content[type].push_back(nextB);
		 _components.push_back(nextB);
	 }
	 
 }

 void MainWindowComponent::addSidebarButton(const std::string& fileLocation,
	 ComponentType type, SDL_Rect& destination)
 {
	 std::ifstream sidebarF(fileLocation);
	 //std::string line;

	 if (sidebarF.fail())
	 {
		 std::cout << "Error file at: " << fileLocation << " missing!" << std::endl;
		 exit(-404);
	 }

	 std::string surfaceLoc;
	 getline(sidebarF, surfaceLoc, '#');

	 SDL_Rect src;
	 sidebarF >> src.x >> src.y >> src.w >> src.h; sidebarF.ignore();

	 NewRoomButtonComponent* button =
		 new NewRoomButtonComponent(surfaceLoc, src, destination, type, this);
	 
	 button->changeAction(ActionType::AWAYS_SHOWN);
	 

	 _content[type].push_back(button);
	 _components.push_back(button);
 }

 void MainWindowComponent::inerCalculateArea()
{
	SideBarComponent* sidebar = static_cast<SideBarComponent*>
		(_content[ComponentType::SIDEBAR].front());

	SDL_Rect sideBarArea = sidebar->getDimentions();

	int windowHeight, windowWidth;
	SDL_GetWindowSize(_window, &windowWidth, &windowHeight);

	_newRoomArea.x = sideBarArea.w;
	_newRoomArea.y = sideBarArea.y;
	_newRoomArea.w = windowWidth ;
	_newRoomArea.h = sideBarArea.h;

}
