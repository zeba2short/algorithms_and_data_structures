#include <vector>
#include <iostream>
#include <algorithm>

#include "algorithms.hpp"

namespace algo
{

std::vector<std::pair<char, char>> levenshtein_edit_instruction(const std::string& s1, const std::string& s2)
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

	std::vector<std::pair<char, char>> opt;

	char match = 'M';
	char insert = 'I';
	char remove = 'D';
	char replace = 'R';

	size_t i = n - 1;
	size_t j = m - 1;

	while (i || j)
	{
		if (i && j)
		{
			if (d[i - 1][j - 1] == d[i][j] && s1[i - 1] == s2[j - 1])
			{
				opt.push_back({match, s2[j - 1]});
				--i;
				--j;
			}
			else if (d[i - 1][j] <= d[i][j - 1] && d[i - 1][j] < d[i - 1][j - 1])
			{
				opt.push_back({remove, s1[i - 1]});
				--i;
			}
			else if (d[i][j - 1] <= d[i - 1][j] && d[i][j - 1] < d[i - 1][j - 1])
			{
				opt.push_back({insert, s2[j - 1]});
				--j;
			}
			else
			{
				opt.push_back({replace, s2[j - 1]});
				--i;
				--j;
			}
		}
		else if (i == 0)
		{
			opt.push_back({insert, s2[j - 1]});
			--j;
		}
		else
		{
			opt.push_back({remove, s1[i - 1]});
			--i;
		}
	}

	std::reverse(opt.begin(), opt.end());
	return opt;
}

unsigned int levenshtein_distance(const std::string& s1, const std::string& s2)
{
	size_t n = s1.size() + 1;
	size_t m = s2.size() + 1;

	if (n == 1)
		return m - 1;
	else if(m == 1)
		return n - 1;

	std::vector<std::vector<size_t>> d(2, std::vector<size_t>(m));

	for (size_t i = 0; i < m; ++i)
		d[0][i] = i;

	size_t current = 1;
	size_t prev = 0;
	for (size_t i = 1; i < n; ++i)
	{
		current = i % 2;
		prev = (i - 1) % 2;
		d[current][0] = i;

		for (size_t j = 1; j < m; ++j)
		{
			size_t left = d[current][j - 1] + 1;
			size_t up = d[prev][j] + 1;
			size_t diagonal = d[prev][j - 1] + ((s1[i - 1] == s2[j - 1]) ? 0 : 1);

			d[current][j] = std::min(left, std::min(up, diagonal));
		}
	}

	return d[current][m - 1];
}

} // namespace algo
