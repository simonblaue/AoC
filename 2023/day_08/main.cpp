/*
Day 08 of AoC
By Simon Blaue
*/

#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include "../include/io.hpp"

using std::vector, std::string, std::map, std::tuple;

map<string,tuple<string,string>> getMaps(vector<string> data){

	map<string,tuple<string,string>> nodes;
	for (int i=2; i<data.size(); i++){
		string l = data[i];
		string actnode = l.substr(0,l.find("=")-1);
		string leftnode = l.substr(l.find("(")+1, 3);
		string rightnode = l.substr(l.find(",")+2, 3);

		tuple<string,string> towards  = {leftnode, rightnode};
		nodes[actnode] = towards;
		// std::cout << actnode << " = (" << leftnode << ", " << rightnode << ")\n";
	}
	return nodes;
}

int partOne(vector<string> data){

	string instructinos = data[0];
	map<string,tuple<string,string>> nodes = getMaps(data);
	
	string actNode = "AAA";
	string end = "ZZZ";

	int i = 0;
	while (actNode != "ZZZ")
	{
		for (char c: instructinos){
			auto [nextLeftnode,nextRightNode] = nodes[actNode];
			i++;
			if (c == 'L')
			{
				actNode = nextLeftnode;
			} else if (c == 'R'){
				actNode = nextRightNode;
			}

			if (actNode == "ZZZ"){
				break;
			}

		}
	}	
	return i;
}

bool gotThere(vector<string> actNodes){
 	for (string node : actNodes){
		if (node[2] != 'Z'){
			return false;
		}
 }
 return true;
}

int partTwo(vector<string> data){

	string instructinos = data[0];
	map<string,tuple<string,string>> nodes = getMaps(data);
	

	//
	vector<string> actNodes;
	for (auto [key,val]: nodes){
		if (key[2] == 'A'){
			actNodes.push_back(key);
		}
	}

	int i = 0;
	while (!gotThere(actNodes))
	{
		for (char c: instructinos){
			i++;

			std::cout << "Going " << c <<" with  nodes: ";
			for (string &actNode:actNodes){
				std::cout << actNode << " ";
				auto [nextLeftnode,nextRightNode] = nodes[actNode];
				if (c == 'L')
				{
					actNode = nextLeftnode;
				} else if (c == 'R'){
					actNode = nextRightNode;
				}
			}
			std::cout << "i="<< i << "\n";
			if (gotThere(actNodes)){
				return i;
			}
		}
	}	
	return i;
}

int main(void)
{


vector<string> data = readInput("testinput.txt");

// int res1 = partOne(data);
int res2 = partTwo(data);

//  std::cout << "The solution to part one is: " <<  res1 << std::endl;

 std::cout << "The solution to part two is: " <<  res2 << std::endl;
	return 0;
}