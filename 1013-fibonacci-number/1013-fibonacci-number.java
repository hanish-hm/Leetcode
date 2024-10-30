class Solution {
    public int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        int prev = 1;
        int prev2 = 0;
        int curr;
        for(int i=2;i<=n;i++){
            curr = prev2+prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
}