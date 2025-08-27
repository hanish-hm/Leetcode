class Solution {
public:
    bool fn(int n,int k,string& str,int& count,vector<int>& vis){
        if(str.size()==n){
            count++;
            if(count == k){
                return true;
            }
            else{
                return false;
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i] = 1;
                str+=to_string(i);
                if(fn(n,k,str,count,vis)){
                    return true;
                }
                str.pop_back();
                vis[i] = 0;
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        string str = "";
        vector<int> vis(n+1,0);
        int count = 0;
        fn(n,k,str,count,vis);
        return str;
    }
};