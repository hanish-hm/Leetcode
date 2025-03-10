class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<string>o;
        for (int i=0;i<board.size();i++){
            string b="";
            for (int j=0;j<board[0].size();j++){
                if (board[i][j]!='.'){b+=board[i][j];}
            }
            if (!b.empty()){sort(b.begin(),b.end());o.push_back(b);}
        }
        for (int i=0;i<board[0].size();i++){
            string b="";
            for (int j=0;j<board.size();j++){
                if (board[j][i]!='.'){b+=board[j][i];}
            }
            if (!b.empty()){sort(b.begin(),b.end());o.push_back(b);}
        }
        string b="";
        for (int i=0;i<7;i+=3){
            for (int j=0;j<7;j+=3){
                string b="";
                if (board[i][j]!='.'){b+=board[i][j];}
                if (board[i][j+1]!='.'){b+=board[i][j+1];}
                if (board[i][j+2]!='.'){b+=board[i][j+2];}
                if (board[i+1][j]!='.'){b+=board[i+1][j];}
                if (board[i+1][j+1]!='.'){b+=board[i+1][j+1];}
                if (board[i+1][j+2]!='.'){b+=board[i+1][j+2];}
                if (board[i+2][j]!='.'){b+=board[i+2][j];}
                if (board[i+2][j+1]!='.'){b+=board[i+2][j+1];}
                if (board[i+2][j+2]!='.'){b+=board[i+2][j+2];}
                if (!b.empty()){sort(b.begin(),b.end());o.push_back(b);}
            }
        }
        for (int i=0;i<o.size();i++){
            for (int j=0;j<o[i].size()-1;j++){
                if (o[i][j]==o[i][j+1]){return false;};
            }
        }
        return true;
    }
};