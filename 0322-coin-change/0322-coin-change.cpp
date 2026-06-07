class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array of size amount + 1, initialized with a value greater than any possible answer
        // Using amount + 1 as "infinity" because the max coins needed can't exceed amount (if using 1-cent coins)
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins are needed to make an amount of 0
        dp[0] = 0;
        
        // Iterate through every amount from 1 to the target amount
        for (int i = 1; i <= amount; i++) {
            // Check every available coin denomination
            for (int coin : coins) {
                // If the coin value is less than or equal to the current amount 'i'
                if (i - coin >= 0) {
                    // Update dp[i] to be the minimum of its current value or 
                    // 1 (current coin) + the min coins needed for the remaining amount (i - coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still amount + 1, it means the amount cannot be formed
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
