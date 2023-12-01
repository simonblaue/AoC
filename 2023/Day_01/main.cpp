/*
Day 01 of AoC
By Simon Blaue
*/

#include <iostream>
#include <numeric>

#include "../include/io.hpp"

using std::vector, std::string;


int partOne( vector<string> data){

    vector<vector<int>> extractedDigits;
    for (string &line: data){
        vector<int> extractedDigitsPerLine;
        for (char &c : line){
            int d;
            if (std::isdigit(c)){
                d = (int)c - '0';
                extractedDigitsPerLine.push_back(d);
            }
        }
        extractedDigits.push_back(extractedDigitsPerLine);
    }


    std::vector<int> calibrationValues;
    // Combine the first and last digit into two-digit number and print
    for (auto &digits: extractedDigits){
        int calibrationNumber;
        calibrationNumber = *digits.begin()*10 + *(digits.end()-1);
        calibrationValues.push_back(calibrationNumber);
    }

    int result = std::reduce(calibrationValues.begin(), calibrationValues.end());
    return result;
};

int partTwo(vector<string> data){

    return -1;
}

int main(void)
{

    vector<string> data = readInput("input.txt");
    vector<string> data = readInput("testinput.txt");

    int res1 = partOne(data1);
    int res2 = partTwo(data2);

    std::cout << "The result for part One is: " << res1  << std::endl;
    std::cout << "The result for part Two is: " << res2 << std::endl;

	return 0;
}