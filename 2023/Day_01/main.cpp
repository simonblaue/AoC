/*
Day 01 of AoC
By Simon Blaue
*/

#include <iostream>
#include <numeric>
#include <map>
// #include <string>

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


    vector<vector<int>> extractedDigits;
    for (string line: data){
        std::cout << line << " -> ";

        vector<int> extractedDigitsPerLine;
        // Convert all literal digits to char digits.
        vector<string> literalStrings = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<string> literalDigits = {"o1e", "t2o", "t3e", "f4r", "f5e", "s6x", "s7n", "e8t", "n9e"};

        for(size_t j=3; j<line.length()+1; j++){
            string subline = line.substr(0,j);
            for(size_t i=0; i<literalStrings.size(); ++i){
                string str1 = literalStrings[i];
                string str2 = literalDigits[i];
                while (subline.find(str1)!=std::string::npos){
                    line.replace(subline.find(str1), str1.length(), str2);
                    subline.replace(subline.find(str1), str1.length(), str2);
                }
            }
        }


        std::cout << line << " -> ";

        for (char &c : line){
            int d;
            if (std::isdigit(c)){
                d = (int)c - '0';
                extractedDigitsPerLine.push_back(d);
                std::cout << d;
            }
        }
        extractedDigits.push_back(extractedDigitsPerLine);

        std::cout << " -> " << *extractedDigitsPerLine.begin() << *(extractedDigitsPerLine.end()-1) << std::endl;
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
}

int main(void)
{

    vector<string> data1 = readInput("input.txt");
    vector<string> data2 = readInput("input.txt");

    int res1 = partOne(data1);
    int res2 = partTwo(data2);



    std::cout << "The result for part One is: " << res1  << std::endl;
    std::cout << "The result for part Two is: " << res2 << std::endl;

	return 0;
}