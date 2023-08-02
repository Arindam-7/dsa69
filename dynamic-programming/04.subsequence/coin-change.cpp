// https://leetcode.com/problems/coin-change/description/

// memoization
class Solution {
public:
    int f(vector<int>& coins, int amount, vector<vector<int>>& dp, int index) {
        if(index < 0 && amount > 0) return 1e9;
        if(amount == 0) return 0;
        
        if(dp[index][amount] != -1) return dp[index][amount];

        int exclude = f(coins, amount, dp, index-1);
         
        int include = 1e9;
        if(coins[index] <= amount) include = 1 + f(coins, amount - coins[index], dp, index);

        return dp[index][amount] = min(exclude, include);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = f(coins, amount, dp, n-1);
        return (ans >= 1e9) ? -1 : ans;
    }
};

// tabulation 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 1e9));
        
        // amount == 0
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                int exclude = 0 + dp[i-1][j];
                int include = 1e9;
                if(coins[i-1] <= j) include = 1 + dp[i][j - coins[i-1]];

                dp[i][j] = min(include, exclude);
            }
        }

        int ans = dp[n][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};
