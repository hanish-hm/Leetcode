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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjointset ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){continue;}
                int arr1[] = {-1,0,1,0};
                int arr2[] = {0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nr = i + arr1[k];
                    int nc = j + arr2[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        int node = i*n+j;
                        int adjnode = nr*n+nc;
                        ds.unionbysize(node,adjnode);
                    }
                }
            }
        }
        int mx =  0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){continue;}
                int arr1[] = {-1,0,1,0};
                int arr2[] = {0,1,0,-1};
                set<int> st;
                for(int k=0;k<4;k++){
                    int nr = i + arr1[k];
                    int nc = j + arr2[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        st.insert(ds.findulparent(nr*n+nc));
                    }
                }
                int sizetotal = 0;
                for(auto it: st){
                    sizetotal += ds.size[it];
                }
                mx = max(mx,sizetotal+1);
            }
        }

        for(int i =0 ;i < n*n;i++){
            mx = max(mx,ds.size[ds.findulparent(i)]);
        }

        return mx;
    }
};