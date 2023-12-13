/*
Day 12 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <regex>
#include "../include/io.hpp"

using std::vector, std::string, std::regex;

int f(vector<int> nums, string s);

int partOne(vector<string> data){

	int res = 0;
	for (string &line : data){


		// Extracting th counts for continuos demaged groups
		vector<int> nums;
		string strNums = line.substr(line.find(" "), string::npos);


		while (strNums.find(",") != string::npos){
			auto idx = strNums.find(",");
			string num = strNums.substr(0, idx);
			nums.push_back(stoi(num));
			strNums.erase(strNums.begin(),strNums.begin()+ idx+1);
		}
		nums.push_back(stoi(strNums));

		// Extracting open and set groups
		string springs = line.substr(0, line.find(" "));

		res += f(nums, springs);
	}


	return res;
}



int f(vector<int> nums, string s){

	// Finds num[0] times "?" or "#", before are any amount of "."
	string regexstr = "\\.*[?#]{" + std::to_string(nums[0]) + '}';

	std::cout << regexstr << "\n";
	// regex r(regexstr);


	return 0;
}


int main(void)
{


vector<string> data = readInput("testinput.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;
	return 0;
}