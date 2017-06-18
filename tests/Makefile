CXX=g++
CXXFLAGS=--std=c++11 -Wall -Werror
LIBRARY=-lgtest
SRC=main.cpp ../levenshtein_distance.cpp ../max_weight_independent_set_in_tree.cpp

tests:
	$(CXX) $(CXXFLAGS) $(LIBRARY) $(SRC) -o $@

clean:
	rm tests
