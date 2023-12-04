/*
Day 04 of AoC
By Simon Blaue
*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>
#include "../include/io.hpp"

using std::vector, std::string;


int partOne(vector<string> data){

	vector<int> allCardValues;
	for (auto &line : data){

		size_t sepIdx = line.find("|");
		size_t beginIdx = line.find(":");
		string winningNumbersSubString = line.substr(beginIdx+2, sepIdx-beginIdx-2);
		string myNnumbersSubString = line.substr(sepIdx+2, string::npos);

		vector<int> winningNumbers;
		vector<int> myNnumbers;

		size_t idx;
		std::stringstream ss;

		ss << winningNumbersSubString;
		string temp;
		int num;
		while(!ss.eof()){
			ss >> temp;
			if (std::stringstream(temp) >> num){
				winningNumbers.push_back(num);
			}
			temp = "";
		}

		std::stringstream ss2;
		ss2 << myNnumbersSubString;
		temp="";
		while(!ss2.eof()){
			ss2 >> temp;
			if (std::stringstream(temp) >> num){
				myNnumbers.push_back(num);
			}
			temp = "";
		}

		int rightGuesses = 0;
		for (auto winNum: winningNumbers){
			for (auto myNum: myNnumbers){
				if (winNum == myNum){
					rightGuesses += 1;
				}
			}
		}

		int cardValue = std::pow(2, rightGuesses-1);

		std::cout << "Right Guesses: " << rightGuesses << " -Value-> " << cardValue << std::endl;

		allCardValues.push_back(cardValue);

	}


	return std::reduce(allCardValues.begin(), allCardValues.end());
}

int partTwo(vector<string> data){

	return -1;
}

int main(void)
{

	vector<string> data = readInput("input.txt");

	int res1 = partOne(data);
	int res2 = partTwo(data);

	std::cout << "Answer to part one: " << res1 << std::endl;
	std::cout << "Answer to part two: " << res2 << std::endl;

	return 0;
}