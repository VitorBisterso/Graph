#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../SparseMatrix/SparseMatrix/Node.hpp"
#include "../SparseMatrix/SparseMatrix/AvlTree.hpp"
#include "../SparseMatrix/SparseMatrix/Line.hpp"
#include "../SparseMatrix/SparseMatrix/SparseMatrix.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

class Graph
{
    public:
        Graph();

        void addVertex(string);
        void deleteVertex(string);
        void addEdge(string, string, int);
        void deleteEdge(string, string);

        friend ostream& operator<<(ostream&, const Graph&);
    private:
        vector<string> vertexNames;
        SparseMatrix<int>* edges;
};

#include "Graph.cpp"

#endif // GRAPH_HPP
