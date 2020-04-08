#pragma once
#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_Image.h"

#include "RoomWindowComponent.h"
#include "ChangeableTextComponent.h"
#include "BackdropComponent.h"
//#include "Component.h"


class FileSystem
{
public:
	//THIS CLASS IS A SINGLETON !!!!
	static FileSystem& getInstance() 
	{
		static FileSystem instance;
		return instance;
	}
	
	void addSpawner(ComponentType type, Component* spawner)
	{
		_spawners[type] = spawner;
	}

	Component* getSpawner(ComponentType type)
	{
		return _spawners[type];
	}

private:
	FileSystem();
	FileSystem(FileSystem const&) = delete;
	void operator = (FileSystem const&) = delete;

	void loadChangeableTextComponentSpawner()
	{
		std::ifstream file("Files/Data/ChangeableTextComponentSpawner.txt");

		if (file.fail())
		{
			std::cout << "Could not initialize the change able text spawner. File at :"
				"Files/Data/ChangeableTextComponentSpawner.txt not found !" << std::endl;
			exit(-404);
		}
		std::string fontLoc;
		getline(file, fontLoc, '#');
		TTF_Font* font = TTF_OpenFont(fontLoc.c_str(), 26);
		if (!font)
		{
			std::cout << "Error loading TTF font at: " << fontLoc << "TTF_Error: " << TTF_GetError() << std::endl;
			exit(-404);
		}
		SDL_Color color;
		file >> color.r >> color.g >> color.b; file.ignore();

		ChangeableTextComponent* spawner = new ChangeableTextComponent(font, color);
		_spawners[ComponentType::CHANGEABLE_TEXT] = spawner;
	}


	void loadRoomWindowSpawner()
	{
		RoomWindowComponent* spawner = new RoomWindowComponent();
		std::list<Component*>&comps = spawner->getComponents();
		std::unordered_map<ComponentType, std::vector<Component*>>& content = spawner->getContent();

		std::ifstream file("Files/Data/RoomWindowSpawner.txt");
		if (file.fail())
		{
			std::cout << "Could not initialize the change able text spawner. File at :"
				"Files/Data/RoomWindowSpawner.txt not found !" << std::endl;
			exit(-404);
		}

		std::string backDropLoc;
		getline(file, backDropLoc, '#');

		BackdropComponent* backdrop = new BackdropComponent(backDropLoc);
		
	}

	std::unordered_map<ComponentType, Component*> _spawners;
};

