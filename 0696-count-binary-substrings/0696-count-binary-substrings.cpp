class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> v;

        int count = 1;
        char prev = s[0];
        for(int i=1;i<n;i++){
            if(s[i]==prev){
                count++;
            }
            else{
                v.push_back(count);
                count = 1;
                prev = s[i];
            }
        }
        v.push_back(count);
        int ans = 0;
        for(int i=0;i<v.size()-1;i++){
            ans+= min(v[i],v[i+1]);
        }
        return ans;
    }
};