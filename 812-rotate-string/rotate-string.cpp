class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths are different, s cannot be a rotation of goal
        if (s.size() != goal.size()) {
            return false;
        }

        // Concatenate goal with itself and check if s is a substring
        string concatenated = goal + goal;
        return concatenated.find(s) != string::npos;
    }
};