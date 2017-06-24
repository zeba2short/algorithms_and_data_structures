#pragma once

#include <stdexcept>
#include <unordered_set>

#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_list.hpp>

namespace algo
{
namespace graph
{

typedef unsigned int vertex_t;
typedef std::pair<vertex_t, vertex_t> Edge;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> DGraph;

std::unordered_set<vertex_t> find_max_weight_independent_set_in_tree(
		const DGraph& t, const std::vector<unsigned int>& wight);

class NotATree: public std::runtime_error
{
public:

NotATree(): std::runtime_error("not a tree") {}

};

} // namespace graph
} // namespace algo
