class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int nn = n;
        int i =0;
        int ans = 0;
        while(n!=1){
            ans+= 1<<i;
            n = n/2;
            i++;
        }
        ans+= 1<<i;

        return ans^nn;
    }
};