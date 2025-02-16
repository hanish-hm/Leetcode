class Solution {
private:
    int firstindex(vector<int>& nums, int target, int n){
        int index = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + ((high-low)/2);
            if(nums[mid] == target){
                index = mid;
                high = mid-1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return index;
    }
    int lastindex(vector<int>& nums, int target, int n){
        int index = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + ((high-low)/2);
            if(nums[mid] == target){
                index = mid;
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstocc = firstindex(nums,target,n);
        if(firstocc == -1){
            return {-1,-1};
        }
        int lastocc = lastindex(nums,target,n);
        return {firstocc,lastocc};
    }
};