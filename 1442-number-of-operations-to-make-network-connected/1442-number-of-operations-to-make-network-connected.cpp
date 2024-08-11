class Disjointset{
    public: 
    vector<int> parent,rank,size;
    Disjointset(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findulparent(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findulparent(parent[x]);
    }
    void unionbyrank(int u, int v){
        int ulp_u = findulparent(u);
        int ulp_v = findulparent(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u,int v){
        int ulp_u = findulparent(u);
        int ulp_v = findulparent(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int count = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findulparent(u) == ds.findulparent(v)){
                count++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                components++;
            }
        }
        if(count>=components-1){
            return components-1;
        }
        else{
            return -1;
        }
    }
};