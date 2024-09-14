#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>>* adj;

    public:

    Graph(int v)
    {
        this->V = v;
        adj = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    void printGraph()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i <<" : ";
            list<pair<int,int>> neighbour = adj[i];
            
            for(auto u:neighbour)
            {
                cout<<"("<<u.first<<","<<u.second<<"),";;
            }
            cout<<endl;
        }
    }
};


int main()
{

    Graph g(5);
    g.addEdge(0,1,5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,3);
    g.addEdge(2,3,1);
    g.addEdge(2,4,2);
    
    g.printGraph();
}