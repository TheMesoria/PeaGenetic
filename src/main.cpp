#include <iostream>
#include "FileLoader/FileLoader.hpp"

int main()
{
	FileLoader fl;
	fl.addMap("../resources/a280.tsp");
	auto x = fl[0];
	return 0;
}