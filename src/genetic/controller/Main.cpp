//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#include <iostream>
#include "Main.hpp"
#include "../holder/ResourceHolder.hpp"
#include "../algorithm/Analyser.hpp"
#include "../../GreedyAlg/GreedyAlg.hpp"

void Main::HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}
void Main::Start()
{
	std::cout << "Starting..\n\n";
	FileLoader fl;
	fl.addMap("../resources/wi29.tsp");
	
	ResourceHolder rh(fl[0]);
}


