class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()){
            return false;
        }
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(!mp[t[i]]){
                return false;
            }
            mp[t[i]]--;
        }
        return true;
    }
};