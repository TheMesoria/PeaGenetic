//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#include <iostream>
#include <cmath>
#include <functional>
#include "Analyser.hpp"

Analyser::Analyser(std::list<Path> *pool, ResourceHolder *rh) : pool_(pool), rh_(rh)
{
	std::list<Path > kek = *pool;
	for (auto &i : *pool) lengths_.push_back(GetLength(i, rh));
	
}
unsigned Analyser::GetLength(const Path &path, ResourceHolder *rh)
{
	unsigned returnValue=0;
	for (int i = 1; i < path.size(); i++)
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
	if(amount<2) amount = 2;
	
	std::vector<unsigned> contestants;
	
	for(auto i=0u;i<10;i++)
	{
		contestants.push_back(std::rand()%lengths_.size());
	}
	return contestants;
}
std::pair<unsigned, unsigned> Analyser::sortByBestResult(const std::vector<unsigned> &lineUp)
{
	auto best = static_cast<unsigned>(INFINITY), bestInx=0u;
	auto secondBest = static_cast<unsigned>(INFINITY), sBestInx=0u;
	
	for (auto &&item : lineUp)
	{
		auto val=lengths_[item];
		if(val < best)
		{
			secondBest=best;
			sBestInx=bestInx;
			best=val;
			bestInx=item;
		}
		else if(val < secondBest)
		{
			secondBest=val;
			sBestInx=item;
		}
	}
	
	return {static_cast<const unsigned int &>(bestInx), static_cast<const unsigned int &>(sBestInx)};
}
std::vector<Path> Analyser::OX(const std::pair<unsigned, unsigned> &parent)
{
	auto it = pool_->begin();
	std::advance(it,parent.first); 										const Path& a = *it;
	it = pool_->begin();
	std::advance(it,parent.second);										const Path& b = *it;
	
	auto parents = std::make_pair<const Path&, const Path&>(a, b);
	
	
	auto size = static_cast<unsigned>(std::rand()%parents.first.size());
	auto start = static_cast<unsigned>(std::rand()%parents.first.size());
	auto move = static_cast<unsigned>(std::rand()%parents.first.size());
	move = static_cast<unsigned int>(floor(move / 2));
	size = size<1?1:size;
	
	if(start+size > parents.first.size()) size=parents.first.size()-start;
	start = start<move?0:start-move;
	
	Path
			childA(parents.first.size(), 100000),
		 	childB(parents.first.size(), 100000);
	
	for(auto i = start;i<start+size;i++)
	{
		childA[i] = parents.second[i];
		childB[i] = parents.first[i];
	}
	
	auto counter = size+start==parents.first.size()?0:start+size;
	auto calculate = [](const Path &parent, Path &child, const unsigned& start, const unsigned& amount)
	{
		auto checkIfContains = [](const Path& target, const unsigned &value) { for(unsigned val : target)if(val == value) return true;	return false; };
		
		auto tmp = amount-1;
		auto pState=start,cState=start;
		
		child.back()=100000;
		if(start>=parent.size()-2) { pState=0; cState=0; }
		while(tmp!=0)
		{
			auto l = checkIfContains(child,parent[pState]);
			if(!l){ child[cState] = parent[pState]; tmp--; pState++; cState++; }
			else pState++;
			
			if(pState>parent.size()-2) pState=0;
			if(cState>parent.size()-2) cState=0;
			
		}
		
		child.back()=child.front();
		if(checkIfContains(child,100000))
		{
			for (unsigned i = 0; i < parent.size(); i++)
			{
				if(!checkIfContains(child,i))
				{
					for(unsigned &val : child)if(val == 100000) val = i;
				}
			}
		}
		auto crap = checkIfContains(child,100000);
		return;
	};
	calculate(parents.second,childB,counter,parents.first.size()-size);
	calculate(parents.first,childA,counter,parents.first.size()-size);
	
	std::vector<Path> paths;
	paths.push_back(childA);
	paths.push_back(childB);
	
	return paths;
}
void Analyser::Start()
{
//	auto start =22u;
//	auto size = 8u;
//	Path parent = {23,26,28,0,6,5,13,17,25,19,7,3,20,16,14,8,4,2,9,22,27,11,
//				   	12,15,24,21,1,18,10,23};
//	Path child = {100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,
//				  100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,
//					12,15,24,21,1,18,10,23};
//
//	std::cout << parent.size() << "<->" << child.size();
//
//	auto calculate = [](const Path &parent, Path &child, const unsigned& start, const unsigned& amount)
//	{
//		auto checkIfContains = [](const Path& target, const unsigned &value) { for(unsigned val : target)if(val == value) return true;	return false; };
//
//		auto tmp = amount-1;
//		auto pState=start,cState=start;
//
//		child.back()=100000;
//		if(start>=parent.size()-2) { pState=0; cState=0; tmp++; }
//		while(tmp!=0)
//		{
//			auto l = checkIfContains(child,parent[pState]);
//			if(!l){ child[cState] = parent[pState]; tmp--; pState++; cState++; }
//			else pState++;
//
//			if(pState>parent.size()-2) pState=0;
//			if(cState>parent.size()-2) cState=0;
//
//		}
//
//		child.back()=child.front();
//		return;
//	};
//
//	calculate(parent,child,start+size,parent.size()-size);
	
	for (int i = 0; i < 999999; i++)
	{
		auto x = sortByBestResult(getContestants());

		auto res = OX(x);


		lengths_.push_back(GetLength(res[0],rh_));
		lengths_.push_back(GetLength(res[1],rh_));

		auto best = sortByBestResult({x.first,x.second,lengths_.size()-2,lengths_.size()-1});

		lengths_[x.first] = lengths_[best.first];
		lengths_[x.second] = lengths_[best.second];

		auto it = pool_->begin();
		
		std::advance(it,x.first);
		if(best.first == lengths_.size()-2) { *it=res[0]; DrawBeautiful(*it,10,rh_,i); }
		else if(best.first == lengths_.size()-1) { *it=res[1]; DrawBeautiful(*it,10,rh_,i); }

		it = pool_->begin();

		std::advance(it,x.first);
		if(best.second == lengths_.size()-2) { *it=res[0]; DrawBeautiful(*it,10,rh_,i); }
		else if(best.second == lengths_.size()-1) { *it=res[1]; DrawBeautiful(*it,10,rh_,i);}

		lengths_.pop_back();
		lengths_.pop_back();
	}

	std::vector<unsigned> tmp;
	for (int j = 0; j < lengths_.size(); j++) tmp.push_back(j);
	std::pair<unsigned, unsigned> res = sortByBestResult(tmp);;

	std::cout << "\n`````````````````````````````````````````````````\n\n";
	std::cout << "Result: " << lengths_[res.first];
	std::cout << "\n\n\n`````````````````````````````````````````````````\n";
	
	return;
}
void Analyser::DrawBeautiful(const Path &path, const unsigned int &lim, ResourceHolder *rh, unsigned generation)
{
	std::cout << "\n=========================\nGeneracja: " << generation << "\n=========================\n";
	DrawPath(path,lim);
	std::cout << "\tLength: " << GetLength(path,rh) << std::endl;
}

