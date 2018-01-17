//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#pragma once
// <> includes
// "" includes
#include "../holder/ResourceHolder.hpp"

class Analyser
{
	//Let's remember there is no need for mutex. this resource is static!
	std::list<Path>* pool;
	ResourceHolder* rh;
	
public:
	Analyser(std::list<Path>* pool, ResourceHolder* rh);
	static unsigned GetLength(const Path &path, ResourceHolder* rh) const;
};


