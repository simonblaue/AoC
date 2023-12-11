/*
Day 11 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include "../include/io.hpp"
#include <numeric>

using std::vector, std::string, std::reduce;

struct Pos{
	int x;
	int y;
};

inline bool operator<(const Pos& l, const Pos& r){
	return std::tie(l.x, l.y) < std::tie(r.x, r.y);
}
inline bool operator>(const Pos& lhs, const Pos& rhs) { return rhs < lhs; }
inline bool operator<=(const Pos& lhs, const Pos& rhs) { return !(lhs > rhs); }
inline bool operator>=(const Pos& lhs, const Pos& rhs) { return !(lhs < rhs); }

inline bool operator==(const Pos& l, const Pos& r) { 
		return (std::tie(l.x, l.y) == std::tie(r.x, r.y)); }
inline bool operator!=(const Pos& lhs, const Pos& rhs) { return !(lhs == rhs); }

inline std::ostream &operator << (std::ostream &os, Pos &p){
		os << "[" + std::to_string(p.x) + ", " + std::to_string(p.y) + "]";
		return os;
	};

int partOne(vector<string> data){

	// Expand Galaxy

	string emptyrow(data[0].size(), '.');
	// Insert Rows
	vector<int> insertRowsIdx;
	for (int i=0; i<data.size(); i++){
		string line = data[i];
		if (line.find("#") == string::npos){
			insertRowsIdx.push_back(i+insertRowsIdx.size());
		}
	}

	for (int idx: insertRowsIdx){
		// std::cout << "Inserting at " <<idx<<"\n";
		data.insert(data.begin()+idx, emptyrow);
	}

	// Insert cols
	vector<int> insertColsIdx;
	bool foundGalaxy = false;
	for (int j=0; j< data[0].size(); j++){
		foundGalaxy = false;
		for (int i=0; i<data.size(); i++){
			if (data[i][j] == '#') {
				foundGalaxy = true;
				break;
			}
		}
		if (!foundGalaxy) {
			insertColsIdx.push_back(j+insertColsIdx.size());
			foundGalaxy = false;
		}
	}

	for (int j=0; j<data[0].size(); j++){
		if (j == insertColsIdx[0]){
			// std::cout << "Inserting at " << insertColsIdx[0] << "\n";
			for (int i=0; i<data.size(); i++){
				data[i].insert(data[i].begin()+insertColsIdx[0], '.');
			}
			insertColsIdx.erase(insertColsIdx.begin());
		}
	}

	// Print expanded Universe
	// for (string line : data){
	// 	std::cout << line << "\n";
	// }

	// Find Positions
	vector<Pos> glaxies;
	for (int i=0; i<data.size(); i++){
		for (int j=0; j<data[i].size(); j++){
			if ((data[i][j]) == '#'){
				glaxies.push_back({i,j});
			}
		}
	}

	vector<int> distances;
	for (Pos p1: glaxies){
		for (Pos p2:glaxies){
			if (p1 == p2){ 
				// std::cout << "- ";
				continue;}
			// Calculate distance
			int dist = abs(p1.x-p2.x) + abs(p1.y-p2.y);
			// std::cout << dist << " ";
			distances.push_back(dist);
		}
		// std::cout << "\n";
	}


	return reduce(distances.begin(), distances.end())/2;
}

int main(void)
{


vector<string> data = readInput("input.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;
	return 0;
}