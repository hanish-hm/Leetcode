class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());

        for(int i = 0; i < (pow(2,n)); i++){
            bitset<16> b(i);
            string s = b.to_string().substr(16 - n);

            if(!st.count(s))
                return s;
        }

        return "";
    }
};  