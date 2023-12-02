/*
Day 02 of AoC
By Simon Blaue
*/

#include <iostream>
#include "../include/io.hpp"
#include <map>
#include <numeric>

using std::vector, std::string;

const vector<string> searchValues  ={"red", "green", "blue"};

void fillMap(std::map<string,int> &m, string token){
	for (auto c: searchValues){
		int val;
		size_t idx;
		if ((idx = token.find(c)) != std::string::npos){
			val = stoi(token.substr(idx-3, idx));
			// std::cout << val << "\n";
			if (m[c] < val) {m[c] = val;}
		}
	}
}

int partOne(vector<string> data){
	// only 12 red cubes, 13 green cubes, and 14 blue cubes
	vector<std::map<string,int>> allGames;
	vector<int> validGamesIDs;
	vector<int> invalidGamesIDs;

	for (auto &line : data){

		size_t posGameId = line.find(":");
		string gameId = line.substr(5, posGameId-5);
		string games = line.substr(line.find(":")+1, std::string::npos);

		string token;
		size_t pos;

		// Keep track of how many have been pulled maximal
		std::map<string, int> m; 
		m["red"] = 0;
		m["green"] = 0;
		m["blue"] = 0;

		while ((pos = games.find(";")) != std::string::npos)
		{
			
			token = games.substr(0, pos+1);
			games.erase(0, pos+1);
			fillMap(m,token);
		}
		fillMap(m,games);		
		allGames.push_back(m);

		if (m["red"]<=12 && m["green"]<=13 && m["blue"]<=14){
			validGamesIDs.push_back(stoi(gameId));
			std::cout << "Possible Game: " << stoi(gameId) << " with: "
				<< m["red"] << ", " 
				<< m["green"] << ", "
				<< m["blue"] << " \n";
		} else {
			invalidGamesIDs.push_back(stoi(gameId));
			std::cout << "Impossible Game: " << stoi(gameId) << " with: "
				<< m["red"] << ", " 
				<< m["green"] << ", "
				<< m["blue"] << " \n";
		}
	}



	return std::reduce(validGamesIDs.begin(), validGamesIDs.end());
}

int partTwo(vector<string> data){
	vector<std::map<string,int>> allGames;
	vector<int> gamePower;
	vector<int> invalidGamesIDs;

	for (auto &line : data){

		size_t posGameId = line.find(":");
		string gameId = line.substr(5, posGameId-5);
		string games = line.substr(line.find(":")+1, std::string::npos);

		string token;
		size_t pos;

		// Keep track of how many have been pulled maximal
		std::map<string, int> m; 
		m["red"] = 0;
		m["green"] = 0;
		m["blue"] = 0;

		while ((pos = games.find(";")) != std::string::npos)
		{
			
			token = games.substr(0, pos+1);
			games.erase(0, pos+1);
			fillMap(m,token);
		}
		fillMap(m,games);		
		allGames.push_back(m);

		// Calculate the power of a game
		int power = m["red"] * m["green"] * m["blue"];
		gamePower.push_back(power);
	}

	return std::reduce(gamePower.begin(), gamePower.end());

}


int main(void)
{

	vector<string> data = readInput("input.txt");

	int res1 = partOne(data);
	int res2 = partTwo(data);

	std::cout << "The solution two part one is: " << res1 << std::endl;
	std::cout << "The solution two part two is: " << res2 << std::endl;

	return 0;
}