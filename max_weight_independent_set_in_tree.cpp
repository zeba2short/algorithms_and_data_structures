#include "graph_algorithms.hpp"
#include <tuple>

namespace algo
{
namespace graph
{

namespace
{

vertex_t find_tree_root(const DGraph& t)
{
	std::vector<bool> v(num_vertices(t), false);

	boost::graph_traits<DGraph>::edge_iterator begin, end;
	for (std::tie(begin, end) = edges(t); begin != end; ++begin)
		v[target(*begin, t)] = true;

	for (auto it = v.begin(); it != v.end(); ++it)
		if (!*it) return it - v.begin();

	throw NotATree();
}

typedef std::pair<unsigned int, unsigned int> vertexWeight;

void find_weight(const DGraph& tree, const std::vector<unsigned int>& weight,
                 vertex_t v, std::vector<vertexWeight>& m)
{
	boost::graph_traits<DGraph>::out_edge_iterator begin, end;
	m[v] = {weight[v], 0};
	
	for (std::tie(begin, end) = out_edges(v, tree); begin != end; ++begin)
	{
		auto u = target(*begin, tree);
		find_weight(tree, weight, u, m);
		m[v].first += m[u].second;
		m[v].second += std::max(m[u].first, m[u].second);
	}

}

void find_set(const DGraph& tree, vertex_t parent,
              const std::vector<vertexWeight>& m, std::unordered_set<vertex_t>& result)
{
	bool parentInSet = (result.find(parent) != result.end());

	boost::graph_traits<DGraph>::out_edge_iterator begin, end;
	for (std::tie(begin, end) = out_edges(parent, tree); begin != end; ++begin)
	{
		auto u = target(*begin, tree);
		if (!parentInSet && m[u].first > m[u].second)
			result.insert(u);
		find_set(tree, u, m, result);
	}
}

} // namespace

std::unordered_set<vertex_t> find_max_weight_independent_set_in_tree(
		const DGraph& t, const std::vector<unsigned int>& weight)
{
	auto root = find_tree_root(t);
	std::vector<vertexWeight> m(num_vertices(t), {0, 0});
	find_weight(t, weight, root, m);

	std::unordered_set<vertex_t> result;
	if (m[root].first > m[root].second)
		result.insert(root);
	find_set(t, root, m, result);

	return result;
}

} // namespace graph
} // namespace algo
