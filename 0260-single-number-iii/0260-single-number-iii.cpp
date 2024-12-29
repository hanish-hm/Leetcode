class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xornum = 0;
        for(auto it:nums){
            xornum = xornum^it;
        }
        unsigned int xornum_unsigned = static_cast<unsigned int>(xornum);
        unsigned int rightsetbit = xornum_unsigned^(xornum_unsigned&(xornum_unsigned-1));
        int a = 0;
        int b = 0;
        for(auto it:nums){
            if(it&rightsetbit){
                a = a^it;
            }
            else{
                b = b^it;
            }
        }
        return {a,b};
    }
};