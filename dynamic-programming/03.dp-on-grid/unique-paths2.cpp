// https://leetcode.com/problems/unique-paths-ii/

// memoization
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &obstacle) {
        if(m == 0 && n == 0 && obstacle[m][n] != 1) {
            return 1;
        }
        if(m < 0 || n < 0) {
            return 0;
        }
        if(obstacle[m][n] == 1) {
            return 0;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        int up = solve(m - 1, n, dp, obstacle);
        int left = solve(m, n - 1, dp, obstacle);

        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(m - 1, n - 1, dp, obstacleGrid);
    }
};


// tabulation
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> dp(m+1, vector<int> (n+1));
      dp[0][0] = 1;

      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          if(obstacleGrid[i][j] == 1) dp[i][j] = 0;

          dp[i+1][j] += dp[i][j];
          dp[i][j+1] += dp[i][j];
        }
      }

      return dp[m-1][n-1];
    }
};
