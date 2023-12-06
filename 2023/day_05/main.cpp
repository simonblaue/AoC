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


std::vector<vector<vector<long long>>> parseTheThing(vector<string> data){

	vector<vector<vector<long long>>> AllMaps; 
	vector<vector<long long>> actMap;
	for(auto lineIt =  data.begin()+3; lineIt <= data.end(); lineIt++){
		if (*lineIt == ""){
			lineIt += 2;
			AllMaps.push_back(actMap);
			actMap = {};
		}

		std::stringstream ss;
		ss << *lineIt;
		string temp;
		vector<long long> tempNums;
		while (!ss.eof())
		{
			ss >> temp;
			long long num;
			if (std::stringstream(temp) >> num){
				tempNums.push_back(num);
			}
			temp = "";
		}
		actMap.push_back(tempNums);
	}

	return AllMaps;
}

long long partOne(vector<string> data){

	// Extract all seeds from first line
	vector<long long> seeds;
	std::stringstream seedsSS(data[0].substr(data[0].find(":")+2, string::npos));
	string temp;
	long long num;
	while (!seedsSS.eof()){
		seedsSS >> temp;
		if (std::stringstream(temp) >> num){
			seeds.push_back(num);
		}
	}

	// Get an array of Maps 
	vector<string> mapNames = {"seed2soil", "soil2fert", "fert2wat", "wat2light", "light2temp", "temp2humid", "humid2loc"};
	vector<vector<vector<long long>>> AllMaps = parseTheThing(data);

	for (auto &seed: seeds){
		for (auto [maps,mapName] : std::views::zip(AllMaps, mapNames)){
			for (auto range: maps){
				long long rangeLen = range[2];
				long long srcRangStart = range[1];
				long long dstRangStart = range[0];
				long long offset = dstRangStart - srcRangStart;
				 if (seed >= srcRangStart && seed < srcRangStart+rangeLen){
					seed+=offset;
					break;
				}
			}
			// std::cout << mapName + " [" << seed << "], ";
		}
		// std::cout << std::endl;
	}

	return std::ranges::min(seeds);
}


long long partTwo(vector<string> data){

		// Extract all seeds from first line
	vector<long long> rangeseeds;
	std::stringstream seedsSS(data[0].substr(data[0].find(":")+2, string::npos));
	string temp;
	long long num;
	while (!seedsSS.eof()){
		seedsSS >> temp;
		if (std::stringstream(temp) >> num){
			rangeseeds.push_back(num);
		}
	}

	vector<long long> seeds;
	for (size_t i=0; i<rangeseeds.size(); i+=2){
		auto seedrange = std::views::iota(rangeseeds[i], rangeseeds[i]+rangeseeds[i+1]);
		for (auto seed : seedrange){
			seeds.push_back(seed);
		}
	}

	// Get an array of Maps 
	vector<string> mapNames = {"seed2soil", "soil2fert", "fert2wat", "wat2light", "light2temp", "temp2humid", "humid2loc"};
	vector<vector<vector<long long>>> AllMaps = parseTheThing(data);

	for (auto &seed: seeds){
		for (auto [maps,mapName] : std::views::zip(AllMaps, mapNames)){
			for (auto range: maps){
				long long rangeLen = range[2];
				long long srcRangStart = range[1];
				long long dstRangStart = range[0];
				long long offset = dstRangStart - srcRangStart;
				 if (seed >= srcRangStart && seed < srcRangStart+rangeLen){
					seed+=offset;
					break;
				}
			}
			// std::cout << mapName + " [" << seed << "], ";
		}
		// std::cout << std::endl;
	}

	return std::ranges::min(seeds);
}

int main(void)
{

	vector<string> data = readInput("input.txt");

	auto res1 = partOne(data);
	auto res2 = partTwo(data);

	std::cout << "The solution to part one is: " <<  res1 << std::endl;
	std::cout << "The solution to part two is: " <<  res2 << std::endl;

	return 0;
}