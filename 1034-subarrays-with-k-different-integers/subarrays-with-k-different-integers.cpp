class Solution {
public:
    int func(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;
        while (r < nums.size()) {
            mpp[nums[r]]++;  // Increment the count of nums[r] in the map
            while (mpp.size() > k) {  // Shrink the window if the number of distinct elements exceeds k
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);  // Count the number of valid subarrays
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);
    }
};