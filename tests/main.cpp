#include <iostream>

#include "gtest/gtest.h"

#include "../algorithms.h"
#include "../graph_algorithms.h"

namespace
{

class LevenshteinDistanceTest: public ::testing::Test
{
};

typedef LevenshteinDistanceTest LDT;

TEST_F(LDT, all_operations)
{
	auto opt = algo::levenshtein_edit_instruction("exponential", "polynomial");
	std::vector<std::pair<char, char>> expect_opt = {
		{'D', 'e'},
		{'D', 'x'},
		{'M', 'p'},
		{'M', 'o'},
		{'R', 'l'},
		{'R', 'y'},
		{'M', 'n'},
		{'I', 'o'},
		{'R', 'm'},
		{'M', 'i'},
		{'M', 'a'},
		{'M', 'l'}
	};

	// there are more than one possible optimal operations sequence
	// TODO: add all optimal operations sequence
	ASSERT_EQ(opt, expect_opt);
}

TEST_F(LDT, remove_only)
{
	auto opt = algo::levenshtein_edit_instruction("abc", "");
	std::vector<std::pair<char, char>> expect_opt = {
		{'D', 'a'},
		{'D', 'b'},
		{'D', 'c'}
	};
	ASSERT_EQ(opt, expect_opt);
}

TEST_F(LDT, insert_only)
{
	auto opt = algo::levenshtein_edit_instruction("", "abc");
	std::vector<std::pair<char, char>> expect_opt = {
		{'I', 'a'},
		{'I', 'b'},
		{'I', 'c'}
	};
	ASSERT_EQ(opt, expect_opt);
}

TEST_F(LDT, match_only)
{
	auto opt = algo::levenshtein_edit_instruction("abc", "abc");
	std::vector<std::pair<char, char>> expect_opt = {
		{'M', 'a'},
		{'M', 'b'},
		{'M', 'c'}
	};
	ASSERT_EQ(opt, expect_opt);
}

TEST_F(LDT, no_operation)
{
	auto opt = algo::levenshtein_edit_instruction("", "");
	std::vector<std::pair<char, char>> expect_opt = {};
	ASSERT_EQ(opt, expect_opt);
}

TEST_F(LDT, distance_all_operation)
{
	auto d = algo::levenshtein_distance("exponential", "polynomial");
	ASSERT_EQ(d, 6);
}

TEST_F(LDT, distance_remove_only)
{
	auto d = algo::levenshtein_distance("abc", "");
	ASSERT_EQ(d, 3);
}

TEST_F(LDT, distance_insert_only)
{
	auto d = algo::levenshtein_distance("", "abc");
	ASSERT_EQ(d, 3);
}

TEST_F(LDT, distance_match_only)
{
	auto d = algo::levenshtein_distance("abc", "abc");
	ASSERT_EQ(d, 0);
}

TEST_F(LDT, distance_no_operation)
{
	auto d = algo::levenshtein_distance("", "");
	ASSERT_EQ(d, 0);
}

class MaxWeightIndependentSetTest: public ::testing::Test
{
};

typedef MaxWeightIndependentSetTest MWIST;

namespace
{

template <typename T>
void insert_edges(T& t, const std::vector<algo::graph::Edge>& edges)
{
	for (const auto& edge: edges)
		add_edge(edge.first, edge.second, t);
}

} // namespace

TEST_F(MWIST, find_max_weight_independent_set_in_tree_test_simple)
{
	algo::graph::DGraph t(3);
	insert_edges(t, {{0, 1}, {0, 2}});

	auto s = algo::graph::find_max_weight_independent_set_in_tree(t, {4, 2, 3});

	std::unordered_set<algo::graph::vertex_t> result = {1, 2};
	ASSERT_EQ(s, result);
}

TEST_F(MWIST, find_max_weight_independent_set_in_tree_test)
{
//           ___________0[6]__________
//          |            |            |
//      ____1[4]     ___2[8]___      3[8]_____
//     |     |      |    |     |      |       |
//    4[5]   5[6]  6[2] 7[8]   8[3]  9[9]     10[7]
//               _______|______       |
//              |       |      |      |
//             11[5]  12[4]   13[6]  14[2]
//
	algo::graph::DGraph t(15);
	insert_edges(t, {
			{0, 1}, {0, 2}, {0, 3},
			{1, 4}, {1, 5},
			{2, 6}, {2, 7}, {2, 8},
			{3, 9}, {3, 10},
			{7, 11}, {7, 12}, {7, 13},
			{9, 14}
	});

	auto s = algo::graph::find_max_weight_independent_set_in_tree(
			t, {6, 4, 8, 8, 5, 6, 2, 8, 3, 9, 7, 5, 4, 6, 2});

	std::unordered_set<algo::graph::vertex_t> result = {0, 4, 5, 6, 11, 12, 13, 8, 9, 10};
	ASSERT_EQ(s, result);
}

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
