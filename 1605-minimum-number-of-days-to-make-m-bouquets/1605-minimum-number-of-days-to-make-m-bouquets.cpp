class Solution {
private: 
    int count(int mid, int k, int n, vector<int>& bloomDay){
        int count = 0;
        int x = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                x += count/k;
                count = 0;
            }
        }
        x += count/k;
        return x;
    }
    void find(int& low, int& high, int n,vector<int>& bloomDay){{
        for(int i=0;i<n;i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
    }

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<((long long)m*(long long)k)){
            return -1;
        }
        int low = INT_MAX, high = INT_MIN;
        int ans = -1;
        find(low,high,n,bloomDay);
        while(low<=high){
            int mid = low + ((high-low)/2);
            int countx = count(mid,k,n,bloomDay);
            if(countx >= m){
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