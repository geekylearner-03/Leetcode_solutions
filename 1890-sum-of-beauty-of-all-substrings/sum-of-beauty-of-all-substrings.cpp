class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // Frequency map for characters
            multiset<int> freqSet;   // To track frequencies

            for (int j = i; j < n; j++) {
                char c = s[j];
                if (freq[c - 'a'] > 0) {
                    freqSet.erase(freqSet.find(freq[c - 'a'])); // Remove old frequency
                }
                freq[c - 'a']++; // Update frequency
                freqSet.insert(freq[c - 'a']); // Insert new frequency

                // Beauty of the current substring
                int leastFrequent = *freqSet.begin();
                int mostFrequent = *freqSet.rbegin();
                ans += mostFrequent - leastFrequent;
            }
        }

        return ans;
    }
};