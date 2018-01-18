//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Analyser.hpp"

Analyser::Analyser(std::list<Path> *pool, ResourceHolder *rh) : pool_(pool), rh_(rh)
{
	std::list<Path > kek = *pool;
	for (auto &i : *pool)
	{
		lengths_.push_back(GetLength(i, rh));
		Analyser::DrawPath(i,6);
		std::cout << "\tLength: " << GetLength(i,rh) << std::endl;
	}
	
}
unsigned Analyser::GetLength(const Path &path, ResourceHolder *rh)
{
	unsigned returnValue=0;
	for (int i = 1; i < path.size(); ++i)
	{
		returnValue+=rh->getMap().at(path[i-1]).at(path[i]);
	}
	return returnValue;
}
const void Analyser::DrawPath(const Path &path, const unsigned &lim)
{
	if(path.empty()) return;
	std::cout << "~~[";
	for (int i = 0; i < lim && i<path.size(); ++i)
	{
		std::cout << path[i] << ", ";
	}
	std::cout << " ... ]~~";
}
std::vector<unsigned> Analyser::getContestants()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));
	auto amount = std::rand()%lengths_.size();
	
	std::vector<unsigned> contestants;
	
	for(auto i=0u;i<amount;i++)	contestants.push_back(std::rand()%lengths_.size());
	return contestants;
}
std::pair<unsigned, unsigned> Analyser::sortByBestResult(const std::vector<unsigned> &lineUp)
{
	auto best = static_cast<unsigned>(INFINITY);
	auto secondBest = static_cast<unsigned>(INFINITY);
	
	for (auto &&item : lineUp)
	{
		auto val=lengths_[item];
		if(val < best)
		{
			secondBest=best;
			best=val;
		}
		else if(val < secondBest)
		{
			secondBest=val;
		}
	}
	
	return {best,secondBest};
}
std::pair<Path, Path> Analyser::OX(const std::pair<Path,Path> &parents)
{
	std::srand(static_cast<unsigned int>(time(nullptr)));
	auto size = std::rand()%parents.first.size();
	auto start = std::rand()%parents.first.size();
	
	if(start+size > parents.first.size()) size=parents.first.size()-start;
	
	return {};
}
void Analyser::Start()
{
	auto x = sortByBestResult(getContestants());
	//auto res = std::pair<Path,Path>{1,2};
	OX({});
}

