class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            if(ans == ""){
                break;
            }
            if(ans.size()>strs[i].size()){
                ans = ans.substr(0,strs[i].size());
            }
            while(ans!= strs[i].substr(0,ans.size())){
                ans = ans.substr(0,ans.size()-1);
            }
        }
        return ans;
    }
};