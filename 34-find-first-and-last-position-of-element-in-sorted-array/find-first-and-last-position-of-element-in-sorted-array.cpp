class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
        
        while(left <= right) {
            if(nums[left] == target && nums[right] == target) {
                ans = {left, right};
                return ans;
            }
            else if(nums[left] == target && nums[right] != target) right--;
            else if(nums[right] == target && nums[left] != target) left++;
            else {
                left++;
                right--;
            }
        }
        
        return {-1, -1};
    }
};