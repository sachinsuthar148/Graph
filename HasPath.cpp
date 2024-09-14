#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            list<int> neighbour = adj[i];
            for (auto u : neighbour)
            {
                cout << u << ",";
            }
            cout << endl;
        }
    }
    bool hasPathHelper(int src, int dest, vector<bool> &visited)
    {
        if (src == dest)
        {
            return true;
        }
        visited[src] = true;
        list<int> neighbours = adj[src];

        for (auto v : neighbours)
        {
            if (!visited[v])
            {
                if (hasPathHelper(v, dest, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest)
    {
        vector<bool> visited(V, false);
        return hasPathHelper(src, dest, visited);
    }
};

int main()
{
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    // graph.addEdge(5, 6);

    // graph.print();
    // graph.bfs();
    // graph.dfs();
    cout << graph.hasPath(5, 6);
}