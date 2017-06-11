#pragma once

#include <string>

namespace algo
{

unsigned int levenshtein_distance(const std::string& s1, const std::string& s2);
std::vector<std::pair<char, char>> levenshtein_edit_instruction(const std::string& s1, const std::string& s2);

} // namespace algo
