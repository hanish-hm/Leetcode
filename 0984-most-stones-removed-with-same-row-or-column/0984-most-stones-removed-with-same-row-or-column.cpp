class Disjointset{
    public:
    vector<int> size,parent;
    Disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findulparent(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findulparent(parent[x]);
    }

    void unionbysize(int u,int v){
        int ulparent_u = findulparent(u);
        int ulparent_v = findulparent(v);
        if(ulparent_u == ulparent_v){
            return;
        }
        if(size[ulparent_u] < size[ulparent_v]){
            parent[ulparent_u] = ulparent_v;
            size[ulparent_v] += size[ulparent_u];
        }
        else{
            parent[ulparent_v] = ulparent_u;
            size[ulparent_u] += size[ulparent_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row=0;
        int col = 0;
        for(auto it:stones){
            row = max(row,it[0]);
            col = max(col,it[1]);
        }
        int n = stones.size();
        Disjointset ds(row+col+1);
        unordered_map<int,int> stonenodes;
        for(auto it: stones){
            int noderow = it[0];
            int nodecol = it[1]+row+1;
            ds.unionbysize(noderow,nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int count = 0;
        for(auto it: stonenodes){
            if(ds.findulparent(it.first) == it.first){
                count++;
            }
        }
        return n-count;
    }
};