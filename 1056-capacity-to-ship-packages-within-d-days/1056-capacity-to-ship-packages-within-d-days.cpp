class Solution {
private:
    void find(int& low, int& high, int n,vector<int>& weights){
        for(int i=0;i<n;i++){
            high += weights[i];
            low = max(low,weights[i]);
        }
    }
    int calculate(vector<int>& weights,int mid,int n){
        int x = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(count+weights[i]<=mid){
                count += weights[i];
            }
            else{
                x++;
                count = weights[i];
            }
        }
        return x+1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0;
        int high = 0;
        int ans = -1;
        find(low,high,n,weights);
        while(low<=high){
            int mid = low + ((high-low)/2);
            int calc = calculate(weights,mid,n);
            if(calc<=days){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};