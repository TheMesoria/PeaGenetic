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
	std::vector<Path> OX(const std::pair<unsigned, unsigned>& parents);
public:
	
	Analyser(std::list<Path>* pool, ResourceHolder* rh);
	void Start();
	
	static const void DrawPath(const Path &path, const unsigned& lim);
	static void DrawBeautiful(const Path &path, const unsigned& lim, ResourceHolder* rh, unsigned generation = 0);
	static unsigned GetLength(const Path &path, ResourceHolder* rh);
};


