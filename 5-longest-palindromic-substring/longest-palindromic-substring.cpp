class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int longlen = 1;

        // DP table initialization
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        // Substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                t[i][i + 1] = true;
                start = i;
                longlen = 2;
            }
        }

        // Substrings of length 3 or more
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                    if (l > longlen) {
                        longlen = l;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, longlen);
    }
};
