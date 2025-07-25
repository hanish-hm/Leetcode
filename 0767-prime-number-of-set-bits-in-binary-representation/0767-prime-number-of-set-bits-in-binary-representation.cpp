class Solution {
public:
    int totalsetbits(int n){
        int setbits = 0;
        while(n>1){
            if(n%2!=0){
                setbits++;
            }
            n=n/2;
        }
        setbits++;
        return setbits;
    }
    bool isprime(int n){
        if(n<2){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i=left;i<=right;i++){
            int setbits = totalsetbits(i);
            if(isprime(setbits)){
                count++;
            }
        }
        return count;
    }
};