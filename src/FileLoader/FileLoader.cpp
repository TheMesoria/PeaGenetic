//
// Created by freed on 12/7/2017.
//
#include "FileLoader.hpp"
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>

Map FileLoader::operator[](size_t pos) const
{
    return this->availableMapVector_[pos];
}

void FileLoader::addMap(std::string path)
{
	std::fstream file(path,std::ios::in);
    if(!file.good()) return;
	while(true)
	{
		std::string tmp;
		std::getline(file,tmp);
//		std::cout<< tmp << std::endl << std::boolalpha << (tmp == "NODE_COORD_SECTION") << std::endl;
//		std::cout << tmp.size() <<std::endl;
//		std::cout << ((std::string)"NODE_COORD_SECTION").size() <<std::endl;
//		//std::cout<< path << std::endl;
		//if(tmp.compare("NODE_COORD_SECTION"))
		if(tmp.find("NODE_COORD_SECTION") != std::string::npos)
		{
			loadCoordPoints(file);
			loadPointedMap(availableCoordMapVector_.back());
			break;
		}
	}
}

void FileLoader::loadPointedMap(CoordMap coordMap)
{
	Map tmpMap;
	for(auto coord : coordMap )
	{
		std::vector<unsigned> tmp;
		for(auto testCoord : coordMap)
		{
			auto result = sqrt(pow(testCoord.first-coord.first, 2)+pow(testCoord.second-coord.second,2));
			tmp.push_back(static_cast<unsigned int>(result));
		}
		tmpMap.push_back(tmp);
	}
	
	this->availableMapVector_.push_back(tmpMap);
}
void FileLoader::loadCoordPoints(std::fstream &file)
{
	unsigned name;
	double coordX, coordY;
	CoordMap coordMap;
	while(file >> name >> coordX >> coordY)
	{
		coordMap.emplace_back(coordX,coordY);
	}
	this->availableCoordMapVector_.emplace_back(coordMap);
}
