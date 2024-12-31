class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if((dividend<0 && divisor>=0) || (dividend>=0 && divisor<0)){
            sign = -1;
        }
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        long long bigdividend = abs((long long)dividend);
        long long bigdivisor = abs((long long)divisor);
        long long count = 0;
        while(bigdividend>=bigdivisor){
            int x = 0;
            while(bigdividend>=(bigdivisor<<x+1)){
                x++;
            }
            bigdividend -= (bigdivisor<<x);
            count += (1<<x);
        }
        return count*sign;
    }
};