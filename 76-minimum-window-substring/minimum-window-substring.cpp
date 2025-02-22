class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for (char c : t) {
            mpp[c]++; // Initialize the map with characters from t
        }

        int l = 0, r = 0, minLen = INT_MAX, sIndex = -1, cnt = 0, n = s.size(), m = t.size();

        while (r < n) {
            // If the current character is in t, increment the count
            if (mpp[s[r]] > 0) {
                cnt++;
            }
            mpp[s[r]]--; // Decrement the count in the map
            r++; // Move the right pointer

            // When all characters in t are matched
            while (cnt == m) {
                // Update the minimum window if the current window is smaller
                if (r - l < minLen) {
                    minLen = r - l;
                    sIndex = l;
                }

                // Move the left pointer to try to find a smaller window
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) {
                    cnt--; // If the character was part of t, decrement the count
                }
                l++;
            }
        }

        // Return the smallest window or an empty string if no window exists
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};