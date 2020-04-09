namespace Graphv1
    {
    class Graph
        {
        public:
            Graph(size_t vertexCount);
    
            auto addEdge(size_t src, size_t dest)   -> void;
            auto deleteEdge(size_t src, size_t dest)-> void;
            auto printAllAdjacentVertices()         -> void;
    
        private:
            const size_t  m_vertexCount;
            std::list<size_t> *m_adjacentNodes;
        };
    }

namespace Graphv2
    {
    class Graph
        {
        public:
            Graph(size_t vertexCount);
    
            auto addEdge(size_t src, size_t dest)   -> void;
            auto deleteEdge(size_t src, size_t dest)-> void;
            auto printAllAdjacentVertices()         -> void;
    
        private:
            const size_t  m_vertexCount;
            bool        **m_adjacentNodes;
        };
    }