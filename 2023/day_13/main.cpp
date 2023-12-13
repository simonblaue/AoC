/*
Day 13 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <numeric>
#include "../include/io.hpp"

using std::vector, std::string, std::reduce;

void printPattern(vector<string> p){
	for (string l:p){
		std::cout << l << "\n";
	}
	std::cout << "\n";
}

int getMirrorAxisVertical(vector<string> p){
	// Mirrored in row dir
	size_t maxMirrorAxis = p[0].size()-1;
	for (int k=1; k<maxMirrorAxis; k++){
		int j=1;
		bool looping = true;
		while( k-j>=0 && k+j-1<p[0].size() && looping){
			for (int i=0; i<p.size(); i++){
				if (p[i][k-j] != p[i][k+j-1]){
					looping = false;
					break;
				}
			}
			j++;
		}
		if (looping){
			return k;
		}
	}
	return 0;
}

int getMirrorAxisHorizontal(vector<string> p){
	// Mirrored in row dir
	size_t maxMirrorAxis = p.size()-1;
	for (int k=1; k<maxMirrorAxis; k++){
		int j=1;
		bool looping = true;
		while( k-j>=0 && k+j-1<p.size() && looping){
			for (int i=0; i<p.size(); i++){
				if (p[k-j][i] != p[k+j-1][i]){
					looping = false;
					break;
				}
			}
			j++;
		}
		if (looping){
			return k;
		}
	}
	return 0;
}

int partOne(vector<string> data){
	
	// Extract each pattern
	vector<vector<string>> patterns;
	vector<string> pattern;

	vector<int> res1_vertical,res2_horizontal;

	for (string line: data){
		if (line == "") {
			patterns.push_back(pattern);
			pattern.clear();
			continue;
		}
		pattern.push_back(line);
	}
	patterns.push_back(pattern);

	
	for (auto p: patterns){

		res1_vertical.push_back(getMirrorAxisVertical(p));
		if (*res1_vertical.end() == 0){
			res2_horizontal.push_back(getMirrorAxisHorizontal(p));
		}
	}

	int r_vertical = reduce(res1_vertical.begin(),res1_vertical.end());
	int r_horizontal= reduce(res2_horizontal.begin(),res2_horizontal.end());

	return r_horizontal * 100 + r_vertical;
}

int main(void)
{


vector<string> data = readInput("testinput.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;
	return 0;
}