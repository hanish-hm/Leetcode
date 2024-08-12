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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjointset ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionbysize(i,mp[mail]);
                }
            }
        }
        vector<string> mergedmails[n];
        for(auto it:mp){
            string mail = it.first;
            int node = ds.findulparent(it.second);
            mergedmails[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedmails[i].size() == 0){
                continue;
            }
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            sort(mergedmails[i].begin(),mergedmails[i].end());
            for(auto it:mergedmails[i]){
                string mail = it;
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};