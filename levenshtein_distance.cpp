#include <vector>
#include <iostream>
#include <algorithm>

#include "algorithms.h"

namespace algo
{

unsigned int levenshtein_distance(const std::string& s1, const std::string& s2)
{
	size_t n = s1.size() + 1;
	size_t m = s2.size() + 1;

	std::vector<std::vector<size_t>> d(n, std::vector<size_t>(m));

	for (size_t i = 0; i < n; ++i)
		d[i][0] = i;

	for (size_t i = 0; i < m; ++i)
		d[0][i] = i;

	for (size_t i = 1; i < n; ++i)
	{
		for (size_t j = 1; j < m; ++j)
		{
			size_t left = d[i][j - 1] + 1;
			size_t up = d[i - 1][j] + 1;
			size_t diagonal = d[i - 1][j - 1] + ((s1[i - 1] == s2[j - 1]) ? 0 : 1);

			d[i][j] = std::min(left, std::min(up, diagonal));
		}
	}

	return d[n - 1][m - 1];
}

} // namespace algo
