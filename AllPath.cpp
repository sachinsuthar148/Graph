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

       void allPathHelper(int src, int dest, vector<bool> &visited,string path)
       {
            //creating base case

            if(src==dest)
            {
                cout<<path<<dest<<endl;
                return;
            }

            visited[src]=true;
            path+= to_string(src);
            list<int> neighbour  = adj[src];

            for(auto u : neighbour)
            {
                if(!visited[u])
                {
                    allPathHelper(u,dest,visited,path);
                }
            } 

            path=path.substr(0,path.size()-1);
            visited[src]=false;

       }
       void allPath(int src, int dest)
       {
            vector<bool> visited(V,false);
            string path = "";

            allPathHelper(src,dest,visited, path);
       }

}; 


int main()
{
    Graph graph(6,false);
    graph.addEdge(5,0);
    graph.addEdge(5,2); 
    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,1);
    graph.addEdge(4,0);

    graph.print();

    // cout<<   graph.directedCycle();
    graph.allPath(5,1);
}