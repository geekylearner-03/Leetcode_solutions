class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
if (nums.empty()) return 0;  // Edge case: empty input

        std::set<int> st(nums.begin(), nums.end());  // Sorts and removes duplicates
        int maxLength = 1;  // At least 1 if nums is non-empty
        int currentLength = 1;

        // Iterate through the sorted set to find consecutive sequences
        auto it = st.begin();
        int prev = *it;
        ++it;

        for (; it != st.end(); ++it) {
            if (*it == prev + 1) {  // Check if consecutive
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 1;  // Reset sequence
            }
            prev = *it;
        }

        return maxLength;
    }
};