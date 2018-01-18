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
	std::list<Path>* pool_;
	std::vector<unsigned> lengths_;
	ResourceHolder* rh_;
	
	
	std::vector<unsigned> getContestants();
	std::pair<unsigned, unsigned> sortByBestResult(const std::vector<unsigned>& lineUp);
	std::pair<Path,Path> OX(const std::pair<Path,Path>& parents);
	
public:
	Analyser(std::list<Path>* pool, ResourceHolder* rh);
	void Start();
	
	
	static unsigned GetLength(const Path &path, ResourceHolder* rh);
	static const void DrawPath(const Path &path, const unsigned& lim);
};


