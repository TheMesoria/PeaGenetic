//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#pragma once
// <> includes
#include <list>
#include <mutex>
// "" includes
#include "../../FileLoader/FileLoader.hpp"


using Path = std::vector<unsigned>;

class ResourceHolder
{
	Map map;
	std::list<std::list<Path>> availableGenePools;
	
	std::mutex bestPathMutex;
	Path bestPath;
	unsigned length;
public:
	explicit ResourceHolder(const Map &map);
	
	unsigned int getLength() const;
	const Map &getMap();
	void setBetterResult(Path path, unsigned length);
private:
	std::list<Path> GeneratePool(unsigned amount);
};


