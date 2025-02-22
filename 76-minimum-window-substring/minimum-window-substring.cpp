class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for (char c : t) {
            mpp[c]++;
        }

        int l = 0, r = 0, minLen = INT_MAX, sIndex = -1, cnt = 0, n = s.size(), m = t.size();

        while (r < n) {
            if (mpp[s[r]] > 0) {
                cnt++;
            }
            mpp[s[r]]--;
            r++;

            while (cnt == m) {
                if (r - l < minLen) {
                    minLen = r - l;
                    sIndex = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};