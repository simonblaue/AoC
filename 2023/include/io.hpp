#pragma once

#include <fstream>



std::vector<std::string> readInput(std::string filename)
{
    std::vector<std::string> readInput;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // using printf() in all tests for consistency
            printf("%s\n", line.c_str());
            readInput.push_back(line.c_str());
        }
        file.close();
    }

    return readInput;
}
