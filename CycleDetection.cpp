//Cycle Detection for undirected Graph
#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V;
    list<int>* adj;

    public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"Node "<<i<< " : ";
            list<int> neighbour = adj[i];
            for(auto n : neighbour)
            {
                cout<<n<<","; 
            } 
            cout<<endl;
        }
    }

    bool undirectedCycleHandler(int src, int parent, vector<bool> &visited)
    {
        visited[src]=true;
        list<int> neighbour = adj[src];
        for(int i: neighbour)
        {
            if(!visited[i])
            {
                if(undirectedCycleHandler(i,src,visited))
                {
                    return true;
                }
            }
            else
            {
                if(i != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool undirectedCycle()
    {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(undirectedCycleHandler(i,-1,visited))
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

int main()
{
    Graph graph(5);
    graph.addEdge(0,1);
    // graph.addEdge(0,2);  
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);
   
    // graph.addEdge(2,8);
    cout<<graph.undirectedCycle(); 

}