class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(st.find(n) == st.end()){
            int x = n;
            int sum = 0;
            st.insert(n);
            while(x>0){
                sum += ((x%10)*(x%10));
                x = x/10;
            }
            if(sum == 1 || sum == 7){
                return true;
            }
            n = sum;
        }
        return false;
    }
};