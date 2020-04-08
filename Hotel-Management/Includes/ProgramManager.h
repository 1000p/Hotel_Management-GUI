#pragma once

#include "Program.h"
//class Program;

class ProgramManager
{
public:

	static void setProgram(Program& program)
	{
		ourProgram = &program;
	}

	static Program* getProgram()
	{
		return ourProgram;
	}

private:
	static Program* ourProgram;
};

