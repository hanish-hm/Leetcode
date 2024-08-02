class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int src = it[0];
            int dest = it[1];
            int val = it[2];
            adj[src].push_back({dest,val});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int val = q.front().second.second;
            q.pop();
            if(stops>k){continue;}
            for(auto it:adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                if(val+edgewt<dist[adjnode]){
                    dist[adjnode] = edgewt+val;
                    q.push({stops+1,{adjnode,val+edgewt}});
                }
            }
        }
        if(dist[dst] == 1e9){return -1;}
        return dist[dst];
    }
};