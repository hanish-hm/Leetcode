class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> x(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || i==j){
                    x[j] = 1;
                }
                else{
                    x[j] = ans[i-1][j]+ans[i-1][j-1];
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};