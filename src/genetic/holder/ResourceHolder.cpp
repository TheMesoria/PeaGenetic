//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#include <ctime>
#include <iostream>
#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder(const Map &map) : map(map)
{
	for(auto i = 0u; i<1000;i++)
	{
		availableGenePools.push_back(GeneratePool(25));
	}
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
		Path path;
		while(count > 0)
		{
			auto rnd = static_cast<unsigned>(std::rand()%count);
			auto it = temp.begin();
			std::advance(it,rnd);
			path.push_back(*it);
			temp.erase(it);
			
			count--;
		}
		result.push_back(path);
	}
	std::cout << result.size();
	return result;
}
unsigned int ResourceHolder::getLength() const
{
	std::lock_guard<std::mutex> lg(bestPathMutex);
	return length;
}
void ResourceHolder::setBetterResult(Path path, unsigned length)
{
	std::lock_guard<std::mutex> lg(bestPathMutex);
	this->bestPath=path;
	this->length=length;
}
const Map &ResourceHolder::getMap()
{
	return map;
}
