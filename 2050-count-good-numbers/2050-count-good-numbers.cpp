class Solution {
public:
    const int MOD = 1e9+7;
    long long pow(int x,long long n){
        if(n==0){
            return 1;
        }
        long long half = pow(x,n/2);
        if(n%2==0){
            return (half*half)%MOD;
        }
        return (x*half*half)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long evenindices = (n+1)/2;
        long long oddindices = n-evenindices;
        
        long long ans = (pow(5,evenindices)*pow(4,oddindices))%MOD;
        return (int)ans;
    }
};