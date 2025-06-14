class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> a(n);
        a[0] = 1;
        int prev = 1;
        int curr = 0;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                a[i] = a[i-1]+1;
            }
            else{
                a[i] = 1;
            }
        }
        int sum = max(a[n-1],1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                curr = prev+1;
                prev= curr;
            }
            else{
                curr = 1;
                prev = curr;
            }
            sum += max(a[i],curr);
        }
        
        return sum;
    }
};