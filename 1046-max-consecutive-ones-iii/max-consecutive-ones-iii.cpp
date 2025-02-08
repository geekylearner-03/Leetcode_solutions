class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeroes = 0, maxlen = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                zeroes++; // Increment zero count
            }

            // If zeroes exceed k, move the left pointer to shrink the window
            while (zeroes > k) {
                if (nums[l] == 0) {
                    zeroes--; // Decrement zero count
                }
                l++; // Always move the left pointer
            }

            // Update the maximum window length
            maxlen = max(maxlen, r - l + 1);

            r++; // Move the right pointer
        }
        return maxlen;
    }
};