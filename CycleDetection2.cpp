//for directed graph

#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    bool undir;

    public:
        Graph(int V, bool undir=true)
        {
            this->V = V;
            this->undir = undir;
            adj = new list<int> [V];
        }

        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            if(undir)
            {
                adj[v].push_back(u);
            }
        }

        void print()
        {
            for(int i=0;i<V;i++)
            {
                cout<<i<<" : ";
                list<int> neighbour = adj[i];

                for(auto v: neighbour)
                {
                    cout<<v<<",";
                }
                cout<<endl;
            }
        }

        bool directedCycleHandler(int src, vector<bool> &visited, vector<bool> &recPath)
        {
            visited[src]=true;
            recPath[src]=true;

            list<int> neighbour = adj[src];

            for(auto i : neighbour)
            { 
                if(!visited[i])
                {
                    if(directedCycleHandler(i,visited,recPath))
                    {
                        return true;
                    }
                }
                else
                {
                    if(recPath[i])
                    {
                        return true;
                    }
                }
            }
            recPath[src]=false;
            return false;
        }

        bool directedCycle()
        {
            vector<bool> visited(V,false);           
            vector<bool> recPath(V,false);
            for(int i=0; i<V;i++)
            {
                if(!visited[i])
                {
                    if(directedCycleHandler(i,visited,recPath))
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
    Graph graph(4,false);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);

    graph.print();

    cout<<   graph.directedCycle();
}