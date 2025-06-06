class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int left = 0;
        int right = 0;
        int m = g.size();
        int n = s.size();
        int count = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(left<m && right<n){
            if(g[left]<=s[right]){
                count++;
                left++;
                right++;
            }
            else if(g[left]>s[right]){
                right++;
            }
        }
        return count;
    }
};