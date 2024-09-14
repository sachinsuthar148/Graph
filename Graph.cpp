#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* adj;

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

    void printGraph()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i <<" : ";

            //kisi ek node ke sare neighbour ko store karte hai
            list<int> neighbour = adj[i];
            
            for(int u:neighbour)
            {
                cout<<u<<",";
            }
            cout<<endl;
        }
    }
};


int main()
{

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printGraph();
}