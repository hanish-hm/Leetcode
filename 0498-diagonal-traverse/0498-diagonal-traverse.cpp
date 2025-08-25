class Solution {
public:
    void trav(int row,int col,vector<vector<int>>& mat,vector<int>& ans,int n,int m,int direction){

        vector<int> x;
        while(row>=0&&col<m){
            x.push_back(mat[row][col]);
            row--;
            col++;
        }
        if(direction == 0){
            reverse(x.begin(),x.end());
        }
        for(int i=0;i<x.size();i++){
            ans.push_back(x[i]);
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i%2==0){
                trav(i,0,mat,ans,n,m,1);
            }
            else{
                trav(i,0,mat,ans,n,m,0);
            }
        }
        for(int i=1;i<m;i++){
            if((n+i-1)%2==0){
                trav(n-1,i,mat,ans,n,m,1);
            }
            else{
                trav(n-1,i,mat,ans,n,m,0);
            }
        }
        return ans;
    }
};