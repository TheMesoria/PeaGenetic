//
// Created by Black on 1/17/2018.
// Copyright (c) 2018 IndustryOfBlack All rights reserved.
//

#include "Analyser.hpp"

Analyser::Analyser(std::list<Path> *pool, ResourceHolder *rh) : pool(pool), rh(rh){}
unsigned Analyser::GetLength(const Path &path, ResourceHolder *rh) const
{
	auto currentLength=0u;
	auto prev = *path.begin();
	for(auto var : path)
	{
		if(prev!=var)
		{
			auto res = rh->getMap()[prev][var];
			
		}
		
		prev=var;
	}
}
