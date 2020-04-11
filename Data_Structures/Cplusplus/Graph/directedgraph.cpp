#include "directedgraph.h"

DirectedGraphv1::DirectedGraph::DirectedGraph(size_t vertexCount)
	: m_vertexCount{ vertexCount }
	{
	m_adjacentNodes = new list<size_t>[m_vertexCount];
	}

auto DirectedGraphv1::DirectedGraph::addEdge(size_t src, size_t dest)
	-> void
	{
	m_adjacentNodes[src].push_back(dest);
	}

auto DirectedGraphv1::DirectedGraph::deleteEdge(size_t src, size_t dest)
	-> void
	{
	m_adjacentNodes[src].remove(dest);
	}

auto DirectedGraphv1::DirectedGraph::printAllAdjacentVertices()
   -> void
	{
	for (auto index = size_t{ 0 }; index < m_vertexCount; ++index)
		for (auto edge : m_adjacentNodes[index])
			std::cout << '[' << index << "]\t--------->\t[" << edge << "]\n";
   }

DirectedGraphv2::DirectedGraph::DirectedGraph(size_t vertexCount)
    : m_vertexCount{ vertexCount }
    {
    m_adjacentNodes = new bool*[vertexCount];
    for (auto index = size_t{ 0 }; index < vertexCount; ++index)
        m_adjacentNodes[index] = new bool[vertexCount]{false};
    }

auto DirectedGraphv2::DirectedGraph::addEdge(size_t src, size_t dest)
	-> void
   {
   m_adjacentNodes[src][dest] = true;
   }

auto DirectedGraphv2::DirectedGraph::deleteEdge(size_t src, size_t dest)
   -> void
   {
   m_adjacentNodes[src][dest] = false;
   }

auto DirectedGraphv2::DirectedGraph::printAllAdjacentVertices()
   -> void
   {
   for (auto x = size_t{ 0 }; x < m_vertexCount; ++x)
   	{
      for (auto y = size_t{ 0 }; y < m_vertexCount; ++y)
      	if (m_adjacentNodes[x][y])
         	std::cout << "[" << x << "]\t---------->\t[" << y << "]\n";
      }
   }