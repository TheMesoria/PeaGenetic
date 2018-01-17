#include <iostream>
#include "FileLoader/FileLoader.hpp"
#include "genetic/controller/Main.hpp"

int main()
{
	FileLoader fl;
	fl.addMap("../resources/a280.tsp");
	auto x = fl[0];
	
	Main::Start();
	
	return 0;
}