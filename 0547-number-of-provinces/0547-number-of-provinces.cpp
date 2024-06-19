class Solution {
public:
    void dfs(vector<int> adj[], int i, vector<int> &vis){
        stack<int> st;
        st.push(i);
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if (!vis[node]) { 
                vis[node] = 1; 

                for(auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
                    if (!vis[*it]) {
                        st.push(*it);
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);
        int count =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(adj,i,vis);
            }
        }
        return count;
    }
};