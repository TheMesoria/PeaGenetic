#pragma once
#include <memory>
#include <algorithm>
#include <list>
#include "../FileLoader/FileLoader.hpp"

class GreedyAlgorithm 
{
	std::list<unsigned> path_;

private:
	std::vector<unsigned> getClosestCity(
		const Map& map,
		std::vector<unsigned>& notVisited,
		const unsigned& start = 0 );

	unsigned findMinElement(
		const std::vector<unsigned> &val,
		std::vector<unsigned> &notVisited);

public:
	static const unsigned INF = 9999;

	std::vector<unsigned> operator()(
			const unsigned& startPoint,
			const Map& cities
	) ;
};
