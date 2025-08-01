class Solution {
public:
    void bfs(int computer,vector<bool>& vis,vector<vector<int>>& v){
        queue<int> q;
        q.push(computer);
        vis[computer] = true;
        while(!q.empty()){
            int computernumber = q.front();
            q.pop();
            for(auto it:v[computernumber]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        int count = 0;
        if(cables<n-1){
            return -1;
        }
        vector<vector<int>> v(n);
        for(auto c:connections){
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,v);
                count++;
            }
        }
        return count-1;
    }
};