class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        bitset<32> b(n);
        string str = b.to_string();
        int x = 31;
        int ans = 0;
        int i = 0;
        while((1<<i)<n){
            
            ans += (str[x]=='1')? 0: (1<<i);
            x--;
            i++;
        }
        return ans;
    }
};