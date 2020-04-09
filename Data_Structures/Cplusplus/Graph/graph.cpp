#include "graph.h"

Graphv1::Graph::Graph(size_t vertexCount)
	: m_vertexCount{ vertexCount }
	{
	m_adjacentNodes = new list<size_t>[m_vertexCount];
	}

auto Graphv1::Graph::addEdge(size_t src, size_t dest)
	-> void
   {
   m_adjacentNodes[src].push_back(dest);
   }

auto Graphv1::Graph::deleteEdge(size_t src, size_t dest)
	-> void
	{
	m_adjacentNodes[src].remove(dest);
	}

auto Graphv1::Graph::printAllAdjacentVertices()
   -> void
	{
	for (auto index = size_t{ 0 }; index < m_vertexCount; ++index)
		for (auto edge : m_adjacentNodes[index])
      	std::cout << '[' << index << "]\t----------\t[" << edge << "]\n";
   }

Graphv2::Graph::Graph(int vertexCount)
    : m_vertexCount{ vertexCount }
    {
    m_adjacentNodes = new bool*[vertexCount];
    for (auto index = size_t{ 0 }; index < vertexCount; ++index)
        m_adjacentNodes[index] = new bool[vertexCount]{false};
    }

auto Graphv2::Graph::addEdge(size_t src, size_t dest)
	-> void
   {
   m_adjacentNodes[src][dest] = true;
   }

auto Graphv2::Graph::deleteEdge(size_t src, size_t dest)
   -> void
   {
   m_adjacentNodes[src][dest] = false;
   }

auto Graphv2::Graph::printAllAdjacentVertices()
   -> void
   {
   for (auto x = size_t{ 0 }; x < m_vertexCount; ++x)
   	{
      for (auto y = size_t{ 0 }; y < m_vertexCount; ++y)
      	if (m_adjacentNodes[x][y])
         	std::cout << "[" << x << "]\t----------\t[" << y << "]\n";
      }
   }