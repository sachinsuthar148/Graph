#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int v, wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>> &graph, int V)
{
    // Making a priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Making a distance array for calculating the distance from source node
    vector<int> dist(V, INT8_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0; // Corrected to initialize the source node's distance to 0

    while (!pq.empty())
    {
        int u = pq.top().second; // finding the current node
        pq.pop();                // removing the current node from the queue

        vector<Edge> edges = graph[u]; // finding all neighbor nodes of the current node

        for (Edge e : edges)
        {
            if (dist[e.v] > dist[u] + e.wt)
            {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    for (int i : dist)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(3, 7));
    graph[1].push_back(Edge(2, 1));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    // Test case with source node 1
    dijkstra(1, graph, V);
}
