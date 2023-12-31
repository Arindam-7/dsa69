// https://leetcode.com/problems/minimum-path-sum/

// memoization
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &grid) {
        if(m == 0 && n == 0) {
            return grid[m][n];
        }
        if(m < 0 || n < 0) {
            return 1e9;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        int up = grid[m][n] + solve(m - 1, n, dp, grid);
        int left = grid[m][n] + solve(m, n - 1, dp, grid);

        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m - 1, n - 1, dp, grid);
    }
};


// tabulation
class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      vector<vector<int>> dp(m, vector<int> (n, 0));


      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          if(i == 0 && j == 0) dp[i][j] = grid[i][j];
          else {
            int up = grid[i][j];
            if(i > 0) up += dp[i-1][j];
            else up += 1e9;

            int left = grid[i][j];
            if(j > 0) left += dp[i][j-1];
            else left += 1e9;

            
            dp[i][j] = min(up, left);
          }
        }
      }

      return dp[m-1][n-1];
    }
};
