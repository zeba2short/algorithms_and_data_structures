#include <iostream>

#include "gtest/gtest.h"

#include "../algorithms.h"

namespace
{

class LevenshteinDistanceTest: public ::testing::Test
{
};

typedef LevenshteinDistanceTest LDT;

TEST_F(LDT, simple_test)
{
	auto d = algo::levenshtein_distance("exponential", "polynomial");
	ASSERT_EQ(d, 6);
}

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
