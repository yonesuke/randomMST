CC = g++
CFLAGS = -O3 -std=c++11

main: main.cpp unionfind.hpp kruskal.hpp
	$(CC) -o run main.cpp $(CFLAGS)