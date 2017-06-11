#include <iostream>

#include "gtest/gtest.h"

#include "../algorithms.h"

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

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
