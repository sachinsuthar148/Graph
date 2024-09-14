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

        bool isBipartite()
        {
            queue<int> q;
            vector<bool> Visited(V,false);
            vector<int> color(V,-1);
  
            //applying BFS Algorithm
            q.push(0);
            Visited[0]=true;
            color[0]=0;

            while(q.size()>0)
            {
                int curr = q.front();
                q.pop();

                list<int> neighbour = adj[curr];

                for(int v: neighbour)
                {
                    if(!Visited[v])
                    {
                        Visited[v]=true;
                        color[v]= !color[curr];
                        q.push(v);
                    }
                    else
                    {
                        if(color[v]==color[curr])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
}; 


int main()
{
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2); 
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    // graph.addEdge(0,3);

    graph.print();

    // cout<<   graph.directedCycle();
    cout<<graph.isBipartite();
}