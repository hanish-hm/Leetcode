class Solution {
public:
void fn(vector<string>& ans,string digits,unordered_map<char,string> mp,int index,string str){
    if(digits.size() == 0){
        return;
    }
    if(index==digits.size()){
        ans.push_back(str);
        return;
    }
    for(auto c:mp[digits[index]]){
        str+=c;
        fn(ans,digits,mp,index+1,str);
        str.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> mp = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"}, {'9',"wxyz"}
        };
        fn(ans,digits,mp,0,"");
        return ans;
    }
};