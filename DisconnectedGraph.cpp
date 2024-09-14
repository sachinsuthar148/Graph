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

    void bfsHandler(int start, vector<bool> &visited)
    {

        queue<int> q;
        //pushing starting node of graph
        q.push(start);
        visited[start]=true; //mark first node as visited

        while(q.size()>0)
        {
            int u = q.front();
            q.pop();
            cout<<u<<",";
            // finding all neighbourn node and mark as visited
            list<int> neighbour = adj[u];

            for(auto u : neighbour)
            {
                if(!visited[u])
                {
                    q.push(u);
                    visited[u]=true;
                }
            }
        }
    }

    void bfs()
    {
        vector<bool> visited(V,false);
        for(int i=0; i<V;i++)
        {
            if(!visited[i])
            {
                bfsHandler(i,visited);
                cout<<" -- ";
            }
        }
    }


    void dfsHandler(int src, vector<bool> &visited)
    {
        cout<< src<<",";
        visited[src]= true;
        //finding neighbour nodes
        list<int> neighbour = adj[src];

        for(auto u: neighbour)
        {
            if(visited[u] != true)
            {
                dfsHandler(u,visited);
            }
        }
    }

    void dfs()
    {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if( !visited[i])
            {
                dfsHandler(i,visited);
                cout<<" -- ";
            }
        }
    }
};

int main()
{
    Graph graph(10);
    graph.addEdge(0,2);
    graph.addEdge(2,5);
    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,8);
    graph.addEdge(3,7);
    // graph.addEdge(2,8);

    //printing the adjacent lists
    // graph.print();

    cout<<"BFS Traversal is : ";
    graph.bfs();
    cout<<endl;
    cout<<"DFS Traversal is : ";
    graph.dfs();

    cout<<"\nFor Graph 2";

    Graph graph2(7);
    graph2.addEdge(0, 1);
    graph2.addEdge(0, 2);
    graph2.addEdge(1, 3);
    graph2.addEdge(2, 4);
    graph2.addEdge(3, 4);
    graph2.addEdge(3, 5);
    graph2.addEdge(4, 5);

    cout<<endl;
    cout<<"BFS Traversal is : ";
    graph2.bfs();
    cout<<endl;
    cout<<"DFS Traversal is : ";
    graph2.dfs();
}