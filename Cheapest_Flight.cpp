/* 787. Cheapest Flights Within K Stops
Medium
Topics
Companies
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 */



class Solution {
public:
    class Info{
        public:
        int u;
        int stops;
        int cost;

        Info(int u, int cost,int stops)
        {
            this->u = u;
            this->stops = stops;
            this->cost = cost;
        }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(V,INT_MAX);

        dist[src]=0;

        q.push(Info(src,0,-1));

        while(q.size()>0)
        {
            Info current = q.front();
            q.pop();

            for(int i=0;i<flights.size();i++) //flights array has (u,v,wt)
            {
                if(current.u == flights[i][0])
                {
                    int v = flights[i][1]; //for v 
                    int wt = flights[i][2]; //for weight;
                    
                    if(dist[v] > current.cost + wt && current.stops+1 <= k )
                    {
                        dist[v] = current.cost + wt;
                        q.push(Info(v,dist[v], current.stops+1));
                    }
                }
            }
        }

        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};