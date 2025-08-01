class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();
        long long result = 0;
        int sign = 1;
        while(i<n && s[i] == ' '){
            i++;
        }
        if(i<n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i]=='-')? -1:1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            result = 10*result + (s[i]-'0');
            if(sign*result>=INT_MAX){
                return INT_MAX;
            }
            if(sign*result<=INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return sign*result;
    }
};