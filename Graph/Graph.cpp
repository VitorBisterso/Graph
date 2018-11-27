Graph::Graph()
{
    this->edges = new SparseMatrix<int>(0);
}

void Graph::addVertex(string name)
{
    if (!(find(this->vertexNames.begin(), this->vertexNames.end(), name) != this->vertexNames.end()))
        this->vertexNames.push_back(name);
}

void Graph::deleteVertex(string name)
{
    int posVertex = find(this->vertexNames.begin(), this->vertexNames.end(), name) - this->vertexNames.begin();
    if (posVertex < this->vertexNames.size())
    {
        for (int i = 0; i < this->vertexNames.size(); i++)
        {
            if (this->edges->get(i, posVertex) != 0)
                this->edges->put(i, posVertex, 0);

            if (this->edges->get(posVertex, i) != 0)
                this->edges->put(posVertex, i, 0);
        }

        this->vertexNames.erase(remove(this->vertexNames.begin(), this->vertexNames.end(), name), this->vertexNames.end());
    }
}

void Graph::addEdge(string v1, string v2, int weight)
{
    int posV1 = find(this->vertexNames.begin(), this->vertexNames.end(), v1) - this->vertexNames.begin();
    int posV2 = find(this->vertexNames.begin(), this->vertexNames.end(), v2) - this->vertexNames.begin();

    if (posV1 < this->vertexNames.size() && posV2 < this->vertexNames.size() && posV1 != posV2)
        this->edges->put(posV1, posV2, weight);
}

void Graph::deleteEdge(string v1, string v2)
{
    int posV1 = find(this->vertexNames.begin(), this->vertexNames.end(), v1) - this->vertexNames.begin();
    int posV2 = find(this->vertexNames.begin(), this->vertexNames.end(), v2) - this->vertexNames.begin();

    if (posV1 < this->vertexNames.size() && posV2 < this->vertexNames.size())
        this->edges->put(posV1, posV2, 0);
}

ostream& operator<<(ostream &os, const Graph& graph)
{
    os << *graph.edges;
    return os;
}
