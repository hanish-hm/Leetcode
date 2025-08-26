class Solution {
public:
    double finddiagonal(int length,int breadth){
        return sqrt((double)length*length + (double)breadth*breadth);
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int product = 1;
        double maxdiagonal = INT_MIN;
        for(int i=0;i<n;i++){
            int len = dimensions[i][0];
            int breadth = dimensions[i][1];
            double diagonal = finddiagonal(len,breadth);
            if(diagonal>maxdiagonal){
                product = len*breadth;
                maxdiagonal = diagonal;
            }
            else if(diagonal == maxdiagonal){
                product = max(product,len*breadth);
            }
        }
        return product;
    }
};