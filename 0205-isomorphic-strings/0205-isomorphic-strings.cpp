class Solution {
public:
    bool isIsomorphic(string s, string t) {
        string news = "";
        map<char,char> mp;
        map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            char x = t[i];
            if(mp[s[i]] && mp[s[i]]!=x){
                return false;
            }
            if(mp[s[i]]){
                continue;
            }
            else{
                if(mpp[x]){
                    return false;
                }
                mp[s[i]] = x;
                mpp[x]++;
            }
        }
        return true;
    }
};