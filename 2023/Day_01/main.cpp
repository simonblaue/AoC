/*
Day 01 of AoC
By Simon Blaue
*/

#include <iostream>
#include "../include/io.hpp"
#include <regex>

using std::vector, std::string;

int main(void)
{
    vector<string> data = readInput("input.txt");

   

    for (string s: data){
        std::regex digitRegex("(\\d*)");
        auto words_begin = std::sregex_iterator(s.begin(), s.end(), digitRegex);
        auto words_end = std::sregex_iterator();

        std::smatch first_digit = *words_begin;
        std::string match_str = match.str();

        std::cout << "In " + s + " found " + match_str << std::endl;
    }
	return 0;
}