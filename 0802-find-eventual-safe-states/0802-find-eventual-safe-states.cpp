class Solution {
public:
    bool dfs(vector<int>& vis,vector<int>& path,vector<int>& check,int x,vector<vector<int>>& graph){
        vis[x] = 1;
        path[x] = 1;
        
        for(auto it: graph[x]){
            if(!vis[it]){
                if(dfs(vis,path,check,it,graph)){
                    return true;
                }
            }
            else if(path[it]){
                return true;
            }
        }
        
        check[x] = 1;
        path[x] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0);
        vector<int> path(v,0);
        vector<int> check(v,0);
        vector<int> safe;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(vis,path,check,i,graph);
            }
        }
        for(int i=0;i<v;i++){
            if(check[i] == 1){
                safe.push_back(i);
            }
        }
        
        return safe;
    }
};