class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
	    for(auto it:prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    vector<int> indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
        int count =0;
	    while(!q.empty()){
	        int x = q.front();
	        q.pop();
	        count++;
	        for(auto it: adj[x]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    if(count ==N){
	        return true;
	    }
	    return false;
    }
};