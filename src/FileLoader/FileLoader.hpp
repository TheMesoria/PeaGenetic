//
// Created by freed on 12/7/2017.
//

#ifndef PEA2_FILELOADER_HPP
#define PEA2_FILELOADER_HPP

#pragma once
#include <vector>
#include <memory>

using Map = std::vector<std::vector<unsigned>>;
using CoordMap = std::vector<std::pair<double,double>>;

class FileLoader
{
	std::vector <Map> availableMapVector_;
	std::vector <CoordMap> availableCoordMapVector_;
public:
	void addMap(std::string path);
	void loadPointedMap(CoordMap coordMap);
	void loadCoordPoints(std::fstream& file);
	
public:
	FileLoader() = default;
	~FileLoader() = default;

	Map operator[](size_t pos) const;
};

#endif //PEA2_FILELOADER_HPP
