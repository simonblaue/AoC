/*
Day 13 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <numeric>
#include "../include/io.hpp"

using std::vector, std::string, std::reduce;

void printPattern(vector<string> p, vector<int> verticalM={0}, vector<int> horizontalM={0}){
	for (int i=0; i<p.size(); i++){
		string l = p[i];
		if (horizontalM[0] != 0){
			if (std::find(horizontalM.begin(), horizontalM.end(), i) != horizontalM.end()){
				string maxis(l.size(), '-');
				std::cout << maxis << "\n";
			}
		}
		if (verticalM[0] != 0){
			for (int j : verticalM){
				l.insert(verticalM[j], "|");
			}
		}
		std::cout << l << "\n";
	}
}

vector<int> getMirrorAxisVertical(vector<string> p){

	vector<int> allAxis;
	size_t maxMirrorAxis = p[0].size();
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
			allAxis.push_back(k);
		}
	}
	return allAxis;
}

vector<int> getMirrorAxisHorizontal(vector<string> p){
	// Transpose and find
	size_t rows = p.size();
	size_t cols = p[0].size();
	vector<string> pT(cols, string(rows,' '));
	for (size_t i=0; i<p.size(); i++){
		for (size_t j=0; j<p[0].size(); j++){
			pT[j][i] = p[i][j];
		}
	}

	return getMirrorAxisVertical(pT);
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
		vector<int> res1 = getMirrorAxisVertical(p);
		vector<int> res2 = getMirrorAxisHorizontal(p);

		res1_vertical.push_back(reduce(res1.begin(), res1.end()));
		res2_horizontal.push_back(reduce(res2.begin(), res2.end()));

		// printPattern(p, res1,res2);
		// std::cout << "\n\n";
		// std::cout << res1 << " " << res2 << "\n\n";
	}

	int r_vertical = reduce(res1_vertical.begin(),res1_vertical.end());
	int r_horizontal= reduce(res2_horizontal.begin(),res2_horizontal.end());

	return r_horizontal * 100 + r_vertical;
}

int main(void)
{


vector<string> data = readInput("input.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;
	return 0;
}