class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        char maxi = '!';
        for(int i=0;i<num.size()-2;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                maxi = max(maxi,num[i]);
            }
        }
        if(maxi!='!'){
            for(int i=0;i<3;i++){
                ans+=maxi;
            }
        }
        return ans;
    }
};