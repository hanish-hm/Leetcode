class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> a(n);
        vector<int> b(n);
        a[0] = 1;
        b[n-1] = 1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                a[i] = a[i-1]+1;
            }
            else{
                a[i] = 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                b[i] = b[i+1]+1;
            }
            else{
                b[i] = 1;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += max(a[i],b[i]);
        }
        return sum;
    }
};