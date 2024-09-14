#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
    int V;

    list<pair<int, int>> *adj;

    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            list<pair<int, int>> neighbour = adj[i];
            for (auto n : neighbour)
            {
                cout << "(" << n.first << "," << n.second << "), ";
            }
            cout << endl;
        }
    }

    void prims(int src)
    {
        // Creating min Heap --> (weight, u);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> MST(V, false);

        pq.push(make_pair(0, src));
        int ans=0;

        while (pq.size() > 0)
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();


            if (!MST[u])
            {
                list<pair<int, int>> neighbour = adj[u];
                ans+=wt;
                MST[u]=true;
                for (auto n : neighbour)
                {
                    int v = n.first;
                    int currentWt = n.second;
                    pq.push(make_pair(currentWt, v));
                }
            }
        }
        cout<<"OUTPUT IS : "<<ans<<endl;
    }

};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.print();
    g.prims(0);
}