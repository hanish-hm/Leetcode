class Solution {
public:
    double myPow(double x, int n) {
        long long b = n;
        if(b==0){
            return 1;
        }
        
        if(b<0){
            b = abs(b);
            x = 1/x;
        }
        double half = myPow(x,b/2);
        if(b%2==0){
            return half*half;
        }
        return x*half*half;
    }
};