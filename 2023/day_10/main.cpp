/*
Day 10 of AoC
By Simon Blaue

| is a vertical pipe connecting north and south.
- is a horizontal pipe connecting east and west.
L is a 90-degree bend connecting north and east.
J is a 90-degree bend connecting north and west.
7 is a 90-degree bend connecting south and west.
F is a 90-degree bend connecting south and east.
. is ground; there is no pipe in this tile.
S is the starting position of the animal; there is a pipe on this tile, but your sketch doesn't show what shape the pipe has.

*/

#include <iostream>
#include <vector>
#include <string> 
#include <map>
#include "../include/io.hpp"

using std::vector, std::string, std::cout, std::map;

map<char,string> prettyfy{
	{'7',"┓"},
	{'L',"┗"},
	{'J',"┛"},
	{'-',"━"},
	{'F',"┏"},
	{'|',"┃"},
	{'S',"S"},
};

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


Pos getNext(Pos old, Pos act, char pipe){
	// Get next pos from act and old

		bool fromNorth = old.x+1 == act.x;
		bool fromEast = old.y-1 == act.y;
		bool fromSouth = old.x-1 == act.x;
		bool fromWest = old.y+1 == act.y;

		cout << fromNorth << fromEast << fromSouth << fromWest<< "\n";

		bool toNorth = (pipe == '|' || pipe == 'J' || pipe == 'L') && !fromNorth;
		bool toEast = (pipe == '-' || pipe == 'F' || pipe == 'L') && !fromEast;
		bool toSouth = (pipe == '|' || pipe == 'F' || pipe == '7') && !fromSouth;
		bool toWest = (pipe == '-' || pipe == 'J' || pipe == '7') && !fromWest;

		if (toNorth){
			return {act.x-1, act.y};
		}
		if (toEast){
			return {act.x, act.y+1};
		}
		if (toSouth){
			return {act.x+1, act.y};
		}
		if (toWest){
			return {act.x, act.y-1};
		}
}




int partOne(vector<string> data){

	// Construct the maze
	int rows = data.size();
	int cols = data[0].size();

	// For the distant Values
	vector<vector<int>> maze(rows, std::vector<int>(cols, 0));

	Pos s;
	// Get Start pos
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			if (data[i][j] == 'S'){
				s.x = i;
				s.y = j;
				break;
			}
		}
	}

	cout <<  "Start Pos: ["<< s.x << ", " << s.y << "]\n";
	// First step
	// Find possible directions from S

	char north_s = data[s.x-1][s.y];
	char south_s = data[s.x+1][s.y];
	char east_s = data[s.x][s.y+1];
	char west_s = data[s.x][s.y-1];


	vector<Pos> allowed;

	if (north_s == '|' || north_s == 'F' || north_s == '7'){
		allowed.push_back(Pos({s.x-1,s.y}));
	}
	if (south_s == '|' || south_s == 'L' || south_s == 'J'){
		allowed.push_back(Pos({s.x+1,s.y}));
	}
	if (east_s == '-' || east_s == 'J' || east_s == '7'){
		allowed.push_back(Pos({s.x,s.y+1}));
	}
	if (west_s == '-' || west_s == 'L' || west_s == 'F'){
		allowed.push_back(Pos({s.x,s.y-1}));
	}

	Pos old1 = s;
	Pos old2 = s;
	Pos act1 = allowed[0];
	Pos act2 = allowed[1];

	maze[act1.x][act1.y] = 1;
	maze[act2.x][act2.y] = 1;

	// Value of act pipe 
	int i=2;
	while (act1 != act2 && act1 != s && act2 != s){
		cout << "Act1, Act2 " << act1 << ", " << act2 << "\n";
		Pos temp1 = act1; 
		act1 = getNext(old1, act1, data[act1.x][act1.y]);
		old1 = temp1;

		Pos temp2 = act2; 
		act2 = getNext(old2, act2, data[act2.x][act2.y]);
		old2 = temp2;

		maze[act1.x][act1.y] = i;
		maze[act2.x][act2.y] = i;

		i++;
	}

	cout << "Act1 == Act2: " << act1 << " == " << act2 << "\n";


	vector<vector<int>> newMaze(rows*2, vector<int>(cols*2, 0));

	// Print the Maze
	int maxElem = 0;
		for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			int val =  maze[i][j]; 
			if (val > maxElem) {maxElem = val;}
			if (val == 0){
				cout << " ";
			} else{
				cout << prettyfy.find(data[i][j])->second;
				newMaze[i*2][j*2] = 1;
			}
		}
		cout << "\n";
	}

	// Part two with new Maze

	return maxElem;
}





int main(void)
{


vector<string> data = readInput("input.txt");

int res1 = partOne(data);

 std::cout << "The solution to part one is: " <<  res1 << std::endl;
	return 0;
}