class Solution {
public:
    bool isPalindrome(string s) {
        string str1 = "";
        for(int i=0;i<s.size();i++){
            if((s[i] >='a' && s[i]<='z') || (s[i] >='A' && s[i]<='Z')){
                str1 += tolower(s[i]);
            }
            else if((s[i] >='0' && s[i]<='9')){
                str1+= s[i];
            }
            else{
                continue;
            }
        }
        string str2 = str1;
        reverse(str1.begin(),str1.end());
        return str1 == str2;

    }
};