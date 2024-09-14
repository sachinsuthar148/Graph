// Finding topological sorting using bfs for DAG

#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    bool undir;

    public:
        Graph(int V, bool undir=true)
        {
            this->V=V;
            this->undir = undir;
            adj = new list<int>[V];
        }

        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            if(undir==true)
            {
                adj[v].push_back(u);
            }
        }

        void sortingHelper(int src, vector<bool> &visited, stack<int> &s)
        {
            visited[src]=true;
            list<int>neighbour = adj[src];
            for(auto u : neighbour)
            {
                if(!visited[u])
                {
                    sortingHelper(u,visited,s);
                }
            }
            s.push(src);
        }

        void sortingTop()
        {
            vector<bool> visited(V,false);
            stack<int> s;
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                sortingHelper(i,visited,s);

                }
            }

            while(s.size()>0)
            {
                int popped = s.top();
                s.pop();
                cout<<popped<<",";
            }
        }
};


int main()
{
    Graph graph(6,false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.sortingTop();
}