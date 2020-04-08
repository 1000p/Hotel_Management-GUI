#include <iostream>
#include <string>

#include "Program.h"
#include "ProgramManager.h"

FileSystem& fSystem = FileSystem::getInstance();

int main (int argc, char* argv[])
{
	//That is our program
	Program program;

	ProgramManager::setProgram(program);

	if (!program.init())
	{
		return -1;
	}

	while(program.isRunning())
	{		
		program.handleEvent();
		program.update();
		program.draw();
	}

	return 0;
}