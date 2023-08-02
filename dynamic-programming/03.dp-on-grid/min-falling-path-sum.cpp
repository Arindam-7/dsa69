// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> dp(r,vector<int> (c, 0));
        
        // base case - min path from first row to first row's cell is the value of the cell itself
        for(int i = 0; i < c; i++) {
          dp[0][i] = matrix[0][i];
        }

        // try out all possible indexes from 2nd row 
        for(int i = 1; i < r; i++) {
          for(int j = 0; j < c; j++) {
            int up = matrix[i][j] + dp[i-1][j];

            int left_diagonal = matrix[i][j];
            if(j >= 1) left_diagonal += dp[i-1][j-1];
            else left_diagonal += 1e9; // if goes out of bound, make it max poss value, so that it's not considered as minimum 

            int right_diagonal = matrix[i][j];
            if(j < c - 1) right_diagonal += dp[i-1][j+1];
            else right_diagonal += 1e9;


            dp[i][j] = min(up, min(left_diagonal, right_diagonal));
          }
        }

        int ans = INT_MAX;
        for(int i = 0; i < c; i++) {
          ans = min(ans, dp[r-1][i]);
        }

        return ans;
        
    }
};
