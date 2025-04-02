class Solution {
public:
    int lengthOfLongestSubstring(string s) {
unordered_set<char> st;
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window

        for (int right = 0; right < s.size(); right++) {
            // If the character is already in the set, move the left pointer
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]); // Remove the leftmost character
                left++; // Shrink the window from the left
            }
            st.insert(s[right]); // Add the new character to the set
            maxLength = max(maxLength, right - left + 1); // Update max length
        }

        return maxLength;
    }
};