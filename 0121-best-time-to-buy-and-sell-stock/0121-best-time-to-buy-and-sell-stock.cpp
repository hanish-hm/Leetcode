class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i=0;
        int j;
        int maxp = 0;
        for(j=1;j<n;j++){
            int diff = prices[j]-prices[i];
            maxp = max(maxp,diff);
            if(diff<0){
                i = j;
            }
        }
        return maxp;
    }
};