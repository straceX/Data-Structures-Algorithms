#include <list>
#include <utility>

namespace WeightedDirectedGraphv1
    {
    class WeightedDirectedGraph
        {
        public:
            WeightedDirectedGraph(size_t vertexCount);
    
            auto addEdge(size_t src, size_t dest)   -> void;
            auto deleteEdge(size_t src, size_t dest)-> void;
            auto printAllAdjacentVertices()         -> void;
    
        private:
            const size_t                         m_vertexCount;
            std::list<std::pair<size_t,size_t>> *m_adjacentNodes;
        };
    }

namespace WeightedDirectedGraphv2
    {
    class WeightedDirectedGraph
        {
        public:
            WeightedDirectedGraph(size_t vertexCount);
    
            auto addEdge(size_t src, size_t dest)   -> void;
            auto deleteEdge(size_t src, size_t dest)-> void;
            auto printAllAdjacentVertices()         -> void;
    
        private:
            const size_t  m_vertexCount;
            size_t      **m_adjacentNodes;
        };
    }