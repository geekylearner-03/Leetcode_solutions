class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0; // Points to the next position to place a non-val element
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left; // The first `left` elements are non-val
    }
};