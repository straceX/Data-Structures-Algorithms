#include "weighted_directedgraph.h"

WeightedDirectedGraphv1::WeightedDirectedGraph::WeightedDirectedGraph(size_t vertexCount)
	: m_vertexCount{ vertexCount }
	{
	m_adjacentNodes = new list<std::pair<size_t, size_t>>[m_vertexCount];
	}

auto WeightedDirectedGraphv1::WeightedDirectedGraph::addEdge(size_t src, size_t dest, size_t weight)
	-> void
	{
	m_adjacentNodes[src].emplace_back(dest, weight);
	}

auto WeightedDirectedGraphv1::WeightedDirectedGraph::deleteEdge(size_t src, size_t dest, size_t weight)
	-> void
	{
	m_adjacentNodes[src].remove(std::make_pair{dest, weight});
	//m_adjacentNodes[src].remove_if([](const auto rhs){ return rhs.first == dest; });
	}

auto WeightedDirectedGraphv1::WeightedDirectedGraph::printAllAdjacentVertices()
   -> void
	{
	for (auto index = size_t{ 0 }; index < m_vertexCount; ++index)
		for (auto [dest, weight] : m_adjacentNodes[index])
			std::cout << '[' << index << "]\t-----(" << weight << ")---->\t[" << dest << "]\n";
   }

WeightedDirectedGraphv2::WeightedDirectedGraph::WeightedDirectedGraph(size_t vertexCount)
    : m_vertexCount{ vertexCount }
    {
    m_adjacentNodes = new size_t*[vertexCount];
    for (auto index = size_t{ 0 }; index < vertexCount; ++index)
        m_adjacentNodes[index] = new size_t[vertexCount]{0};
    }

auto WeightedDirectedGraphv2::WeightedDirectedGraph::addEdge(size_t src, size_t dest, size_t weight)
	-> void
   {
   m_adjacentNodes[src][dest] = weight;
   }

auto WeightedDirectedGraphv2::WeightedDirectedGraph::deleteEdge(size_t src, size_t dest)
   -> void
   {
   m_adjacentNodes[src][dest] = 0;
   }

auto WeightedDirectedGraphv2::WeightedDirectedGraph::printAllAdjacentVertices()
   -> void
   {
   for (auto x = size_t{ 0 }; x < m_vertexCount; ++x)
   	{
      for (auto y = size_t{ 0 }; y < m_vertexCount; ++y)
      	if (m_adjacentNodes[x][y])
				std::cout << '[' << index << "]\t-----(" << m_adjacentNodes[x][y] << ")---->\t[" << dest << "]\n";
      }
   }

