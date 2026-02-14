class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            while(i>=0 && s[i]==' '){
                i--;
            }
            if(i<0){
                break;
            }
            int j = i;
            while(j>=0 && s[j]!=' '){
                j--;
            }
            ans+=s.substr(j+1,i-j);
            ans+=" ";
            i=j;
        }
        return ans.substr(0,ans.size()-1);
    }
};