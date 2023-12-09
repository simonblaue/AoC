/*
Day 09 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <numeric>
#include "../include/io.hpp"

using std::vector, std::string, std::reduce;

void printData(vector<vector<int>> data){
		// Check if I read everythin correctly
	for (vector<int> seq : data){
		for (int num: seq){
			std::cout << num << " ";
		}
		std::cout << "\n";
	}
}

void printSeq(vector<int> seq){
	for (int num: seq){
		std::cout << num << " ";
	}
}

int recursiveFinder(vector<int> seq){
	std::cout << "Find Recursiv for ";
	printSeq(seq);
	std::cout << "\n";
	vector<int> newVec;
	for (size_t i=0; i<seq.size()-1; i++){
		newVec.push_back(seq[i+1]-seq[i]);
	}

	if (reduce(newVec.begin(), newVec.end()) == 0){
		std::cout << "All zeros\n";
		return seq[seq.size()-1];
	}

	return seq[seq.size()-1]+recursiveFinder(newVec);
}

int iterativeFinder(vector<int> seq){
	int sum = 0;

	while (reduce(seq.begin(), seq.end()) != 0){
		sum += seq[seq.size()-1];
		std::cout << "Act Seq: ";
		printSeq(seq);
		std::cout << "\n";
		std::adjacent_difference(seq.begin(), seq.end(), seq.begin());
		seq.erase(seq.begin());

	}
	return sum;
}

int partOne(vector<string> data){

	// Pasing data to vector of vector of ints
	vector<vector<int>> recordings;
	for (string &line : data){
		vector<int> sequence = stringLine2Int(line);
		recordings.push_back(sequence);
	}


	vector<int> futurVals;
	for (vector<int> seq : recordings){

		int futurVal = iterativeFinder(seq);
		std::cout << " Next: " << futurVal << "\n";
		futurVals.push_back(futurVal);
	}

	return reduce(futurVals.begin(), futurVals.end());
}

int main(void)
{


vector<string> data = readInput("input.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;

	return 0;
}