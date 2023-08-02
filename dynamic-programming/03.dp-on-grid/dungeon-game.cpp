// https://leetcode.com/problems/dungeon-game/description/


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                // princess cell
                if(i == m-1 && j == n-1) dp[i][j] = min(0, dungeon[i][j]);
                // last row
                else if (i == m-1) dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                // last col
                else if (j == n-1) dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                // move down or right?
                else dp[i][j] = min(0, dungeon[i][j] + max(dp[i+1][j], dp[i][j+1]));
            }
        }

        return abs(dp[0][0]) + 1;
    }
};
