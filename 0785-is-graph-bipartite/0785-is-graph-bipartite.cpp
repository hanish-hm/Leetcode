class Solution {
public:
    bool check(vector<int>& vis, vector<vector<int>>& graph, int a){
        
        vis[a] = 0;
        queue<int> q;
        q.push(a);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto it : graph[x]){
                if(vis[it] == -1){
                    vis[it] = !vis[x];
                    q.push(it);
                }
                else if(vis[it] == vis[x]){
                    return false;
                }                
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,-1);
        for(int i=0;i<v;i++){
            if(vis[i] == -1){
                bool ans = check(vis,graph,i);
                if(!ans){
                    return ans;
                }
            }
        }
        return true;
    }
};