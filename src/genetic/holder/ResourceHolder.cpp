//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#include <ctime>
#include <iostream>
#include <thread>
#include "ResourceHolder.hpp"
#include "../algorithm/Analyser.hpp"

ResourceHolder::ResourceHolder(const Map &map) : map(map)
{
	for(auto i = 0u; i<60;i++)
	{
		availableGenePools_.push_back(GeneratePool(20));
	}

	auto it = availableGenePools_.begin();
	Analyser a(&(*it),this);
	a.Start();
	
}
std::list<Path> ResourceHolder::GeneratePool(unsigned amount)
{
	std::srand(static_cast<unsigned int>(time(nullptr)));
	std::list<unsigned> numbers;
	std::list<Path> result;
	auto count = map.size();
	
	for (auto i = 0u; i < map.size(); ++i) numbers.push_back(i);
	
	for(auto i = amount; i > 0; i--)
	{
		auto temp = numbers;
		auto countTmp=count;
		Path path;
		while(countTmp > 0)
		{
			auto rnd = static_cast<unsigned>(std::rand()%countTmp);
			auto it = temp.begin();
			std::advance(it,rnd);
			path.push_back(*it);
			temp.erase(it);
			
			countTmp--;
		}
		path.push_back(path.front());
		result.push_back(path);
	}
	return result;
}
unsigned int ResourceHolder::getLength()
{
	std::lock_guard<std::mutex> lg(bestPathMutex_);
	return length_;
}
void ResourceHolder::setBetterResult(Path path, unsigned length)
{
	std::lock_guard<std::mutex> lg(bestPathMutex_);
	this->bestPath_=path;
	this->length_=length;
}
const Map &ResourceHolder::getMap()
{
	return map;
}
