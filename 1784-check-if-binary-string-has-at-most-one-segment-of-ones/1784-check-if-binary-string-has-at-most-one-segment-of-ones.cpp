class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int x = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                x++;
            }
            if(x && s[i] == '1'){
                return false;
            }
        }
        return true;
    }
};