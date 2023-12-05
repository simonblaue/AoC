import os 
import time


def writeMakefile(dir):
    fp = open(dir+'/makefile', 'w')
    fp.write("CXX=clang++\n")
    fp.write("CXXFLAGS=-std=c++20 -Wall -Wextra\n")
    fp.write("LDFLAGS=$(shell pkg-config )\n\n")
    fp.write("SRCS=main.cpp\n")
    fp.write("TARGET=main\n\n")
    fp.write("all: $(TARGET)\n\n")
    fp.write("$(TARGET): $(SRCS)\n")
    fp.write("	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)\n\n")
    fp.write(".PHONY: clean run\n\n")
    fp.write("clean:\n")
    fp.write("	rm -f $(TARGET)\n\n")
    fp.write("run: $(TARGET)\n")
    fp.write("	./$(TARGET)")
    fp.close()

def writeMainCpp(dir):
    fp = open(dir+'/main.cpp', 'w')
    fp.write(f"/*\nDay {day} of AoC\n")
    fp.write(f"By Simon Blaue\n*/\n\n")
    fp.write("#include <iostream>\n")
    fp.write('#include "../include/io.hpp"\n')
    fp.write('\n')
    fp.write('using std::vector, std::string;\n\n')
    fp.write('int partOne(vector<string> data){\n')
    fp.write('\n\treturn -1;\n}\n')
    fp.write('int partTwo(vector<string> data){\n')
    fp.write('\n\treturn -1;\n}\n')
    fp.write("int main(void)\n{\n\n\n")
    fp.write('vector<string> data = readInput("input.txt");\n\n')
    fp.write('int res1 = partOne(data);\n')
    fp.write('int res2 = partTwo(data);\n')
    fp.write('\n std::cout << "The solution to part one is: " <<  res1 << std::endl;\n')
    fp.write('\n std::cout << "The solution to part two is: " <<  res2 << std::endl;\n')
    fp.write("\treturn 0;\n}")
    fp.close()


if __name__ == "__main__":
    day = time.strftime("%d", time.localtime())
    print(day)
    dir = f"/Users/simonblaue/ownCloud/AoC/2023/day_{day}"
    try:
        os.mkdir(dir)
    except:
        print("Dir alreay exists.")

    # create a empty input text file
    fp = open(dir+'/input.txt', 'w')
    fp.close()

    writeMainCpp(dir)
    writeMakefile(dir)




