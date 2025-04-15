#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result;
        int count = 1;
        for (int i = 0; i < prev.size(); ++i) {
            if (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i];
                count = 1;
            }
        }
        return result;
    }
};