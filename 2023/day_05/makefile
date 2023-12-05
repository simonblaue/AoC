CXX=clang++
CXXFLAGS=-std=c++23 -Wall -Wextra
# LDFLAGS=$(shell pkg-config )

SRCS=main.cpp
TARGET=main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

.PHONY: clean run

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)