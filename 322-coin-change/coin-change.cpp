
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 coins are needed to make amount 0

        // Fill the DP array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // Check if the amount can be made
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};