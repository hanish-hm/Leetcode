class Solution {
public:

    void setprimearr(int n, vector<int>& primearr){
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i){
                primearr[j] = 0;
            }
        }
    }
    
    int countPrimes(int n) {
        int count = 0;
        vector<int> primearr(n+1,1);
        setprimearr(n,primearr);
        for(int i=2;i<n;i++){
            if(primearr[i] == 1){
                count++;
            }
        }
        return count;
    }
};