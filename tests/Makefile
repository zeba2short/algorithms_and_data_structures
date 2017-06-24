CC=gcc
CXX=g++
CFLAGS=-Wall -Werror
CXXFLAGS=--std=c++11 -Wall -Werror
LIBRARY=-lgtest
SRC=main.cpp ../levenshtein_distance.cpp ../max_weight_independent_set_in_tree.cpp
C_SRC=main.c ../max_subarray.c

tests:
	$(CXX) $(CXXFLAGS) $(LIBRARY) $(SRC) -o $@

ctests:
	$(CC) $(CFLAGS) $(C_SRC) -o $@

clean:
	rm -f tests
	rm -f ctests
