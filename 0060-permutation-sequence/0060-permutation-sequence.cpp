class Solution {
public:
    bool fn(){
        return true;
    }
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> fact(n+1, 1);
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            fact[i] = fact[i-1] * i;
        }

        k--; // zero-based index
        string ans = "";
        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i-1];
            ans += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
            k %= fact[i-1];
        }
        return ans;
    }
};