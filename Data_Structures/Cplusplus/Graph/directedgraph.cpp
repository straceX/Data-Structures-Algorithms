#include "directedgraph.h"

DirectedGraph::DirectedGraph(size_t vertexCount)
	: m_vertexCount{ vertexCount }
	{
	m_adjacentNodes = new list<size_t>[m_vertexCount];
	}

auto DirectedGraph::addEdge(size_t src, size_t dest)
	-> void
	{
	m_adjacentNodes[src].push_back(dest);
	}

auto DirectedGraph::deleteEdge(size_t src, size_t dest)
	-> void
	{
	m_adjacentNodes[src].remove(dest);
	}

auto DirectedGraph::printAllAdjacentVertices()
   -> void
	{
	for (auto index = size_t{ 0 }; index < m_vertexCount; ++index)
		for (auto edge : m_adjacentNodes[index])
			std::cout << '[' << index << "]\t--------->\t[" << edge << "]\n";
   }