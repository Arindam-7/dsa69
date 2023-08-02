// https://leetcode.com/problems/maximal-square/description/

// just a slight variation of count-submatrices-with-all-ones 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(); // row
        int n = matrix[0].size(); // column
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        int side = 0;

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];

                if(matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(down, diagonal));

                    side = max(side, dp[i][j]);
                }
            }
        }

        return side*side;
    }
};
