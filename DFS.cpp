#include <iostream>
#include <vector>
#include <list>
#include <queue>

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

    void dfsHelper(int u, vector<bool> &visited)
    {
        visited[u]=true;
        cout<<u<< " ";
        list<int> neighbour = adj[u];

        for(auto v : neighbour)
        {
            if(visited[v] != true)
            {
                dfsHelper(v,visited);
            }
        }
    }

    void dfs()
    {
        vector<bool> visited(V, false);
        dfsHelper(0,visited);
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
    graph.addEdge(5, 6);

    // graph.print();
    // graph.bfs();
    graph.dfs();
}