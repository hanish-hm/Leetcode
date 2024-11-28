class Solution {
private:
    void bfs(int start,vector<int>& vis,vector<int> adj[]){
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(i,vis,adj);
            }
        }
        return count;
    }
};