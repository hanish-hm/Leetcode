class Solution {
private:
    int count(int mid, int n, vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += ceil((double)nums[i] / (double)mid);
        }
        return count;
    }

    void find(int& high, int n, vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            high = max(high, nums[i]);
        }
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = INT_MIN;
        int ans = -1;

        find(high, n, nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int countx = count(mid, n, nums);

            if (countx <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};