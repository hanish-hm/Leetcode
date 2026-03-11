class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int i =0;
        int ans = 0;
        while(n!=1){
            if(n%2==0){
                ans+= 1<<i;
            }
            n = n/2;
            i++;
        }

        return ans;
    }
};