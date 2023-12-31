// https://leetcode.com/problems/coin-change-ii/description/


//tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1));

        // for 1st row
        for(int i = 1; i <= amount; i++) dp[0][i] = 0;

        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                // include
                if(coins[i-1] <= j) dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                // exclude
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][amount];
    }
};
