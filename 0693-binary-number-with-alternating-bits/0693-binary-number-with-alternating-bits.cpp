class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int x= n%2;
        n=n/2;
        while(n>1){
            if(n%2==x){
                return false;
            }
            else{
                x = n%2;
                n=n/2;
            }
        }
        return !(x==n);
    }
};