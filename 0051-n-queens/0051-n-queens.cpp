class Solution {
public:
    bool issafe(vector<string> x,int row, int col,int n){
        int index= col-1;
        while(index>=0){
            if(x[row][index] == 'Q'){
                return false;
            }
            index--;
        }
        int r= row-1,c = col-1;
        while(r>=0&&c>=0){
            if(x[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }
        r= row+1;c = col-1;
        while(r<n&&c>=0){
            if(x[r][c] == 'Q'){
                return false;
            }
            c--;
            r++;
        }
        return true;
    }
    void fn(vector<vector<string>>& ans,int n,vector<string>& x, int column){
        if(column==n){
            ans.push_back(x);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(x,row,column,n)){
                x[row][column] = 'Q';
                fn(ans,n,x,column+1);
                x[row][column] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> x(n);
        string dot = "";
        for(int i=0;i<n;i++){
            dot+=".";
        }
        for(int i=0;i<n;i++){
            x[i] = dot;
        }

        fn(ans,n,x,0);
        return ans;
    }
};