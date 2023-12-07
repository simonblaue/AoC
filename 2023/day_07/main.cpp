/*
Day 07 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include "../include/io.hpp"

using std::vector, std::string;

std::map<char,int> cardValue = {
	{'A', 13},
	{'K', 12},
	{'Q', 11},
	{'J', 10},
	{'T', 9},
	{'9',  8},
	{'8',  7},
	{'7',  6},
	{'6',  5},
	{'5',  4},
	{'4',  3},
	{'3',  2},
	{'2',  1},
	};

std::map<char,int> cardValue2 = {
	{'A', 13},
	{'K', 12},
	{'Q', 11},
	{'T', 10},
	{'9',  9},
	{'8',  8},
	{'7',  7},
	{'6',  6},
	{'5',  5},
	{'4',  4},
	{'3',  3},
	{'2',  2},
	{'J',  1},
	};

std::map<int,string> play2Name = {
	{1, "High Card"},
	{2, "One Pair"},
	{3, "Two Pair"},
	{4, "Three of a kind"},
	{5, "Full House"},
	{6, "Four of a kind"},
	{7, "Five of a kind"}
};

struct Hand {
	string cards;
	int play;
	int bid;
};

bool part2setter = false;

// for part one
bool operator <(const Hand &b, const Hand &a) { 
// Differnt play
			if (a.play != b.play){
				return a.play > b.play;
			// Same Play check for first different card value
			} else {
				int i=0;
				while(a.cards[i] == b.cards[i]){
					i++;
				}
				return cardValue[a.cards[i]] > cardValue[b.cards[i]];
			}
}

// for part 2
struct
{
  bool operator()(Hand b, Hand a) const { 
			// Differnt play
			if (a.play != b.play){
				return a.play > b.play;
			// Same Play check for first different card value
			} else {
				int i=0;
				while(a.cards[i] == b.cards[i]){
					i++;
				}
				return cardValue2[a.cards[i]] > cardValue2[b.cards[i]];
			}
	}
}
customGreater;

int getPlay(string hand){
	vector<int> v;
	std::map<char, int> handMap;
	for (char card : hand){
		handMap[card] += 1;
	}
	for(auto it = handMap.begin(); it != handMap.end(); ++it ) {
        v.push_back( it->second );
	}
	std::sort(v.begin(), v.end(),  std::greater<int>());

	if (part2setter) {
		// If J is not the max number add J else add 1
		if (handMap['J'] != v[0] ){
			v[0] += handMap['J'];
		// Also need to Catch JJJJJ
		} else if ( handMap['J']!= 5) {
			v[0]+= 1;
		}
	}

	if (v[0] == 5){
		return 7;
	} else if (v[0] == 4) {
		return 6;
	}
	else if (v[0] == 3 && v[1] ==2) {
		return 5;
	} else if (v[0] == 3) {
		return 4;
	} else if (v[0] == 2 && v[1] == 2) {
		return 3;
	} else if (v[0] == 2) {
		return 2;
	} else {
		return 1;
	}
}


long partOne(vector<string> data){

	vector<Hand> allHands;
	for (auto &line : data){
		string hand = line.substr(0, line.find(" "));
		int bid = stoi(line.substr(line.find(" ")+1, string::npos));
		Hand h = {hand, getPlay(hand), bid};
		allHands.push_back(h);
	}

	std::sort(allHands.begin(), allHands.end());

	long res = 0;
	int i = 1;
	for (Hand h: allHands){
		std::cout << h.cards << " has " << play2Name[h.play] << " and rank " << i << " with bid " << h.bid << " res is " << h.bid*i << "\n";
		res += h.bid * i;
		i++;
	}

	return res;
}

long part2(vector<string> data){

	vector<Hand> allHands;
	for (auto &line : data){
		string hand = line.substr(0, line.find(" "));
		int bid = stoi(line.substr(line.find(" ")+1, string::npos));
		Hand h = {hand, getPlay(hand), bid};
		allHands.push_back(h);
	}

	std::sort(allHands.begin(), allHands.end(), customGreater);

	long res = 0;
	int i = 1;
	for (Hand h: allHands){
		std::cout << h.cards << " has " << play2Name[h.play] << " and rank " << i << " with bid " << h.bid << " res is " << h.bid*i << "\n";
		res += h.bid * i;
		i++;
	}

	return res;
}

int main(void)
{

	vector<string> data = readInput("input.txt");

	// long res1 = partOne(data);
	part2setter = true;
	long res2 = part2(data);

	// std::cout << "The solution to part one is: " <<  res1 << std::endl;
	std::cout << "The solution to part two is: " <<  res2 << std::endl;
	return 0;
}