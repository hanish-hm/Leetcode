class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string x = "";
        string y = "";
        int countx=0,county=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                x+='0';
                y+='1';
                if(s[i]!='1'){
                    county++;
                }
                else{
                    countx++;
                }
            }
            else{
                y+='0';
                x+='1';
                if(s[i]!='1'){
                    countx++;
                }
                else{
                    county++;
                }
            }
        }
        return min(countx,county);
    }
};