class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        
        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }
        
        // XOR all elements in the array
        for (int num : nums) {
            xor2 ^= num;
        }
        
        // XOR1 ^ XOR2 gives the missing number
        return xor1 ^ xor2;
    }
};
