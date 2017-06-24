#include "algorithms.h"

long max_subarray(int* array, size_t len, size_t* r, size_t* l)
{
	if (!len)
	{
		*r = *l = 0;
		return 0;
	}

	long sum = array[0];
	*r = 0;
	*l = 1;
	long sum_n = sum;

	size_t r_n = 0, l_n = 1;

	for (size_t i = 1; i < len; i++)
	{
		if (sum_n >= 0)
		{
			sum_n += array[i];
			l_n++;
		}
		else
		{
			sum_n = array[i];
			r_n = i;
			l_n = r_n + 1;
		}

		if (sum < sum_n)
		{
			sum = sum_n;
			*r = r_n;
			*l = l_n;
		}
	}

	return sum;
}
