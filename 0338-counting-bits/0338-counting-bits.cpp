class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int count = 0;
            int x = i;
            while(x>1){
                count += x&1;
                x = x>>1;
            }
            if(x==1){
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};