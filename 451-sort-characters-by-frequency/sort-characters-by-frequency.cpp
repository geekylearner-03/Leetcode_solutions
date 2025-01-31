class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap; // Store frequency of each character
        for (char c : s) freqMap[c]++;

        priority_queue<pair<int, char>> maxHeap; // Max-heap (sorted by frequency)
        for (auto& it : freqMap) {
            maxHeap.push({it.second, it.first});
        }

        string ans = "";
        while (!maxHeap.empty()) {
            int freq = maxHeap.top().first;
            char c = maxHeap.top().second;
            maxHeap.pop();
            ans.append(freq, c); // Append `freq` occurrences of `c`
        }
        return ans;
    }
};