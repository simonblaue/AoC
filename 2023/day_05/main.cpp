/*
Day 05 of AoC
By Simon Blaue
*/

#include <iostream>
#include <sstream>
#include <map>
#include <ranges>
#include <vector>
#include <tuple>
#include "../include/io.hpp"

using std::vector, std::string;




int partOne(vector<string> data){

	// Extract all seeds from first line
	vector<int> seeds;
	std::stringstream seedsSS(data[0].substr(data[0].find(":")+2, string::npos));
	string temp;
	int num;
	while (!seedsSS.eof()){
		seedsSS >> temp;
		if (std::stringstream(temp) >> num){
			seeds.push_back(num);
		}
	}

	std::map<int,int> seed2soil;
	std::map<int,int> soil2fert;
	std::map<int,int> fert2water;
	std::map<int,int> water2light;
	std::map<int,int> light2temp;
	std::map<int,int> temp2humid;
	std::map<int,int> humid2loc;


	vector<std::map<int,int>> allMaps = {seed2soil, soil2fert, fert2water, water2light, light2temp, temp2humid, humid2loc};
	auto actMapIt = allMaps.begin();
	for(auto lineIt =  data.begin()+3; lineIt != data.end(); lineIt++){
		std::cout << *lineIt << "\n";
		if (*lineIt == ""){
			lineIt += 2;
			if (actMapIt != allMaps.end()){
				actMapIt++;
				std::cout << "Next Map!\n";
			}
		}

		std::stringstream ss;
		ss << *lineIt;
		string temp;
		vector<int> tempNums;
		while (!ss.eof())
		{
			ss >> temp;
			int num;
			if (std::stringstream(temp) >> num){
				tempNums.push_back(num);
			}
			temp = "";
		}
		// Vectro tempNums with 3 elements, destination range start, source range start length
		auto destRange = std::views::iota(tempNums[0], tempNums[0]+tempNums[2]);
		auto sourceRange = std::views::iota(tempNums[1], tempNums[1]+tempNums[2]);
		auto mapping = std::views::zip(sourceRange, destRange);
		for (auto [src,dist] : mapping){
			(*actMapIt)[src] = dist;
		}
		
	}

	for (auto map: allMaps){
		for (auto &seed: seeds){
			if (auto it = map.find(seed); it != map.end()){
				seed = map[seed];
			}
		}
	}


	return std::ranges::min(seeds);
}

int partTwo(vector<string> data){

	// Extract all seeds from first line
	vector<int> seeds;
	std::stringstream seedsSS(data[0].substr(data[0].find(":")+2, string::npos));
	string temp;
	int num;
	while (!seedsSS.eof()){
		seedsSS >> temp;
		if (std::stringstream(temp) >> num){
			seeds.push_back(num);
		}
	}

	vector<vector<vector<int>>> AllMaps; 
	vector<vector<int>> actMap;
	for(auto lineIt =  data.begin()+3; lineIt != data.end(); lineIt++){
		if (*lineIt == ""){
			lineIt += 2;
			AllMaps.push_back(actMap);
			actMap = {};
		}

		std::stringstream ss;
		ss << *lineIt;
		string temp;
		vector<int> tempNums;
		while (!ss.eof())
		{
			ss >> temp;
			int num;
			if (std::stringstream(temp) >> num){
				tempNums.push_back(num);
			}
			temp = "";
		}
		actMap.push_back(tempNums);
	}

	vector<string> mapNames = {"seed2soil", "soil2fert", "fert2wat", "wat2light", "light2temp", "temp2humid", "humid2loc"};

	for (auto [maps,mapName] : std::views::zip(AllMaps, mapNames)){
		std::cout << "-------\n" << mapName << "\n------\n";
		for (auto &seed: seeds){
			for (auto range : maps){
				int rangeLen = range[2];
				int srcRangStart = range[1];
				int dstRangStart = range[0];
				int offset = dstRangStart-srcRangStart;
				std::cout << seed << " -> ";
				if (seed >= srcRangStart && seed < srcRangStart+rangeLen ){
					seed+=offset;
					std::cout << seed << "\n";
					break;
				}
				std::cout << seed << "\n";
			}
		}
	}

	return std::ranges::min(seeds);
}

int main(void)
{


vector<string> data = readInput("testinput.txt");

// int res1 = partOne(data);
int res1 = partTwo(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;

//  std::cout << "The solution to part two is: " <<  res2 << std::endl;
	return 0;
}