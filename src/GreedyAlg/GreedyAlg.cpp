#include "GreedyAlg.hpp"
#include <iostream>

// HACK
std::vector<unsigned> GreedyAlgorithm::getClosestCity(const Map &map, std::vector<unsigned> &notVisited, const unsigned int &start)
{
	if (notVisited.empty()) { return std::vector<unsigned>(); }
	
	auto availableCities = map[start];
	auto bestCityId = findMinElement(availableCities, notVisited);
	auto bestCity = availableCities[bestCityId];
	
	auto bestPath = getClosestCity(map, notVisited, bestCityId);
	bestPath.push_back(bestCity);
	
	return bestPath;
}

unsigned GreedyAlgorithm::findMinElement(const std::vector<unsigned> &val, std::vector<unsigned> &notVisited)
{
	auto best= val[notVisited[0]];
	auto knownBest = 0u;
	auto knownBestInNotVisited = 0u;
	auto it = 0u;
	
	for (auto var : notVisited)
	{
		if (val[var] <= best || best == 0)
		{
			best = val[var];
			knownBest = var;
			knownBestInNotVisited = it;
		}
		it++;
	}
	path_.push_back(notVisited[knownBestInNotVisited]);
	notVisited.erase(notVisited.begin()+knownBestInNotVisited);
	return knownBest;
}
std::vector<unsigned> GreedyAlgorithm::operator()(const unsigned &startPoint, const Map &cities)
{
	std::vector<unsigned> notVisited;
	for (auto i = 0u; i < cities.size(); i++) { if (startPoint != i) notVisited.push_back(i); }
	
	path_.push_back(startPoint);
	
	auto path = getClosestCity(cities, notVisited, startPoint);
	std::vector<unsigned> ret;
	for(auto x : path_)
	{
		ret.push_back(x);
	}
	path_ = std::list<unsigned>();
	ret.push_back(ret.front());
	return ret;
}