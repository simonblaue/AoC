/*
Day 14 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include "../include/io.hpp"

using std::vector, std::string;

int calculateLoad(vector<string> p){
	int load = 0;
	for (size_t i = 0; i<p.size(); i++){
		int rowLoad = p.size()-i;
		for (size_t j = 0; j<p[i].size(); j++){
			if (p[i][j] == 'O'){
				load += rowLoad;
			}
		}
	}

	for (auto l:p){
		std::cout << l << "\n"; 
	}

	return load;
}

int partOne(vector<string> data){
	int res;

	std::cout << "Befor moving: \n";
	res = calculateLoad(data);
	std::cout << res <<"\n";

	// Transpose the data
	vector<vector<char>> dataT;
	for (size_t j=0; j<data[0].size(); j++){
		vector<char> col;
		for (size_t i = 0; i<data.size(); i++){
			col.push_back(data[i][j]);
		}
		dataT.push_back(col);
	}

	// // print the transpose
	// std::cout << "Transposed: \n";
	// for (auto c : dataT){
	// 	string act_c(c.begin(), c.end());
	// 	std::cout << act_c << "\n";
	// }
	// std::cout << "\n";

	// move the thind
	for (vector<char> &c : dataT){
		bool moving = true;
		while (moving){
			// string act_c(c.begin(), c.end());
			// std::cout << act_c << "\n";
			moving = false;
			for (size_t i=1; i<c.size(); i++){
				if (c[i] == 'O' && c[i-1] == '.'){
					c[i-1] = 'O';
					c[i] = '.';
					moving = true;
				}
			}
		}
	}

	for (size_t i=0; i<data.size(); i++){
		for (size_t j = 0; j<data[0].size(); j++){
			data[i][j] = dataT[j][i];
		}
	}

	std::cout << "After Moving: \n";
	res = calculateLoad(data);

	return res;
}

int main(void)
{


vector<string> data = readInput("input.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;
	return 0;
}