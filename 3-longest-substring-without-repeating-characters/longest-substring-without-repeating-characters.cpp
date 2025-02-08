class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        memset(hash, -1, sizeof(hash));  // Initialize the entire array to -1
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        
        while (r < n) {
            if (hash[s[r]] >= l) {  // If the character is already in the current window
                l = hash[s[r]] + 1; // Move the left pointer to the right of the previous occurrence
            }
            maxlen = max(maxlen, r - l + 1); // Update the maximum length
            hash[s[r]] = r; // Update the last seen index of the character
            r++;
        }
        
        return maxlen;
    }
};