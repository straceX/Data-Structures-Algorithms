#include "weighted_directedgraph.h"

WeightedDirectedGraph::WeightedDirectedGraph(size_t vertexCount)
	: m_vertexCount{ vertexCount }
	{
	m_adjacentNodes = new list<std::pair<size_t, size_t>>[m_vertexCount];
	}

auto WeightedDirectedGraph::addEdge(size_t src, size_t dest, size_t weight)
	-> void
	{
	m_adjacentNodes[src].emplace_back(dest, weight);
	}

auto WeightedDirectedGraph::deleteEdge(size_t src, size_t dest, size_t weight)
	-> void
	{
	m_adjacentNodes[src].remove(std::make_pair{dest, weight});
	//m_adjacentNodes[src].remove_if([](const auto rhs){ return rhs.first == dest; });
	}

auto WeightedDirectedGraph::printAllAdjacentVertices()
   -> void
	{
	for (auto index = size_t{ 0 }; index < m_vertexCount; ++index)
		for (auto [dest, weight] : m_adjacentNodes[index])
			std::cout << '[' << index << "]\t-----(" << weight << ")---->\t[" << dest << "]\n";
   }