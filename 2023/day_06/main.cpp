/*
Day 06 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
#include <ranges>
#include <numeric>
#include <cmath>
#include "../include/io.hpp"

using std::vector, std::string, std::tuple;


int partOne(vector<string> data){

	string lineT = data[0].substr(data[0].find(":"), string::npos);
	string lineD = data[1].substr(data[1].find(":"), string::npos);

	vector<int> ts =  stringLine2Int(lineT);
	vector<int> ds =  stringLine2Int(lineD);

	vector<int> numberOfWays2Win;
	int res = 1;
	for (auto [T,D] : std::views::zip(ts,ds)){
		vector<int> buttonpressLengthsThisRace;
		// std::cout << "next Run\n";
		for (int t=1; t<T; t++){
			int myDist = (T-t) * t;
			if (myDist > D){
				buttonpressLengthsThisRace.push_back(t);
				// std::cout << "Won with time pressed: " << t << " traveld: " << myDist << "\n";
			}
		}
		int nWins = buttonpressLengthsThisRace.size();
		std::cout << nWins << " possibilites to win\n";
		numberOfWays2Win.push_back(nWins);
		res *= nWins;
	}

	return res;
}
int partTwo(vector<string> data){

	// string lineT = data[0].substr(data[0].find(":")+1, string::npos);
	// string lineD = data[1].substr(data[1].find(":")+1, string::npos);

	// std::string::iterator end_pos = std::remove(lineT.begin(), lineT.end(), ' ');
	// lineT.erase(end_pos, lineT.end());
	// int T = stoi(lineT);

	// std::string::iterator end_pos2 = std::remove(lineD.begin(), lineD.end(), ' ');
	// lineD.erase(end_pos2, lineD.end());

	// long T = 46828479;
	// long D = 347152214061471;

	// // T = 71530;
	// // D = 940200;

	// long t1 = T/2 - std::sqrt(T*T/4 - D);
	// long t2 = T/2 + std::sqrt(T*T/4 - D);

	// std::cout << "Lower Bound: " << t1 << "\n";
	// std::cout << "Upper Bound: " << t2 << "\n";

	// long long res = t2 - t1;
	// return res;

	vector<long> ts = {46828479};
	vector<long> ds =  {347152214061471};

	vector<long> numberOfWays2Win;
	int res = 1;
	for (auto [T,D] : std::views::zip(ts,ds)){
		vector<long> buttonpressLengthsThisRace;
		// std::cout << "next Run\n";
		for (int t=1; t<T; t++){
			long myDist = (T-t) * t;
			if (myDist > D){
				buttonpressLengthsThisRace.push_back(t);
				// std::cout << "Won with time pressed: " << t << " traveld: " << myDist << "\n";
			}
		}
		int nWins = buttonpressLengthsThisRace.size();
		std::cout << nWins << " possibilites to win\n";
		numberOfWays2Win.push_back(nWins);
		res *= nWins;
	}

	return res;
}
int main(void)
{


vector<string> data = readInput("input.txt");

// int res1 = partOne(data);
int res2 = partTwo(data);

//  std::cout << "The solution to part one is: " <<  res1 << std::endl;

 std::cout << "The solution to part two is: " <<  res2 << std::endl;
	return 0;
}