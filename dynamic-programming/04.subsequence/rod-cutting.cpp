// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// memo
class Solution{
  public:
    int f(int price[], int maxl, int n, vector<vector<int>> &dp) {
        if(n <= 0 || maxl <= 0) return 0;
        if(dp[n][maxl] != -1) return dp[n][maxl];
        
        if(n <= maxl) dp[n][maxl] = max(price[n-1]+f(price, maxl-n, n, dp), f(price, maxl, n-1, dp));
    
        else dp[n][maxl] = f(price, maxl, n-1, dp);
        
        return dp[n][maxl];
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return f(price, n, n, dp);
    }
};


// tabulation
class Solution{
  public:
    int cutRod(int price[], int n) {
        // create length array
        int length[n];
        for(int i = 1; i <= n; i++) length[i-1] = i;
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // exclude
                dp[i][j] = dp[i-1][j];
                // include
                if(length[i-1] <= j)
                    dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
            }   
        }
        
        return dp[n][n];
    }
};
