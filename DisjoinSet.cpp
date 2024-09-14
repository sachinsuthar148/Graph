#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
        int n;
        vector<int> par;
        vector<int> rank;

        DisjointSet(int n)
        {
            this->n = n;
            for(int i=0;i<n;i++)
            {
                par.push_back(i);
                rank.push_back(0);
            }
        }


        int find(int x)
        {
            if(par[x]== x)
            {
                return x;
            }
            return par[x]= find(par[x]);  // Path compression
        }


        void unionByRank(int a, int b)
        {
            int parA = find(a);
            int parB = find(b);

            if(rank[parA] == rank[parB])
            {
                par[parB]= parA;  //parent A ko parent B ka parent bna do
                rank[parA]++;
            }
            else if(rank[parA] > rank[parB])
            {
                par[parB]= parA;
            }
            else
            {
                par[parA]=parB;
            }
        }

        void getInfo()
        {
            for(int i=0;i<n;i++)
            {
                cout<< i <<" : "<<par[i]<< " - "<<rank[i]<<endl;
            }
        }
};


int main()
{
    DisjointSet d(6);
    d.unionByRank(0,2);
    cout<< d.find(2) <<endl;
    d.unionByRank(1,3);
    d.unionByRank(2,5);
    d.unionByRank(0,3);
    cout<< d.find(2)<<endl;
    d.unionByRank(0,4);
    d.getInfo();
}