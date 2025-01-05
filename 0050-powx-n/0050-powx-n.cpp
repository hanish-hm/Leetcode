class Solution {
public:
    double myPow(double x, int b) {
        int a = b;
        long long n = abs((long long)b);
        double ans = 1;
        while(n>0){
            if(n%2!=0){
                ans *= x;
                n -= 1;
            }
            else{
                x *= x;
                n /= 2;
            }
        }
        if(a < 0){
            return 1.0/ans;
        }
        return ans;
    }
};