#pragma once

#include <fstream>
#include <vector>
#include <sstream>

std::vector<int> stringLine2Int(std::string s){

    std::stringstream ss;
    std::vector<int> nums;
    std::string temp = "";

    ss << s;
    while(!ss.eof()){
        int num;
        ss >> temp;
        if (std::stringstream(temp) >> num){
            nums.push_back(num);
        }
        temp = "";
    }
    return nums;
}

std::vector<long> stringLine2Long(std::string s){

    std::stringstream ss;
    std::vector<long> nums;
    std::string temp = "";

    ss << s;
    while(!ss.eof()){
        long num;
        ss >> temp;
        if (std::stringstream(temp) >> num){
            nums.push_back(num);
        }
        temp = "";
    }
    return nums;
}

template<typename T, typename P>
T remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg;itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}

std::vector<std::string> readInput(std::string filename)
{
    std::vector<std::string> readInput;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // using printf() in all tests for consistency
            // printf("%s\n", line.c_str());
            readInput.push_back(line.c_str());
        }
        file.close();
    }

    return readInput;
}
