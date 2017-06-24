#include <stdio.h>
#include <assert.h>

#include "../algorithms.h"

#define ARRAY_LENGTH(array) (sizeof(array)/sizeof(array[0]))

void max_subarray_test_1(void)
{
	int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	size_t r, l;

	long sum = max_subarray(array, ARRAY_LENGTH(array), &r, &l);

	assert(sum == 7);
	assert(r == 2);
	assert(l == 7);
}

void max_subarray_test_2(void)
{
	int array[] = {-1, 1, -1};
	size_t r, l;

	long sum = max_subarray(array, ARRAY_LENGTH(array), &r, &l);

	assert(sum == 1);
	assert(r == 1);
	assert(l == 2);
}

void max_subarray_test_3(void)
{
	int array[] = {-1, -1, -1};
	size_t r, l;

	long sum = max_subarray(array, ARRAY_LENGTH(array), &r, &l);

	assert(sum == -1);
	assert(r == 0);
	assert(l == 1);
}

void max_subarray_test_4(void)
{
	int array[] = {0, 0, 0};
	size_t r, l;

	long sum = max_subarray(array, ARRAY_LENGTH(array), &r, &l);

	assert(sum == 0);
	assert(r == 0);
	assert(l == 1);
}

void max_subarray_test_5(void)
{
	int array[] = {1, 1, 1};
	size_t r, l;

	long sum = max_subarray(array, ARRAY_LENGTH(array), &r, &l);

	assert(sum == 3);
	assert(r == 0);
	assert(l == 3);
}

int main(void)
{
	max_subarray_test_1();
	max_subarray_test_2();
	max_subarray_test_3();
	max_subarray_test_4();
	max_subarray_test_5();

	printf("ALL TESTS PASSED\n");

	return 0;
}
