class Solution {
private:
    int findmax(vector<int>& piles){
        
        int x = 0;
        for(int i=0;i<piles.size();i++){
            x = max(x,piles[i]);
        }
        return x;
    }
    long long calc(int mid,vector<int>& piles){
        long long x = 0;
        for(int i=0;i<piles.size();i++){
            x += 1+(piles[i]-1)/mid;
        }
        return x;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        
        int high = findmax(piles);
        int ans = -1;
        while(low<=high){
            int mid = low+((high-low)/2);
            long long cal = calc(mid,piles);
            if(cal<=h){
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