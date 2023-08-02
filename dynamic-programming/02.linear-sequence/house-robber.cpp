// https://leetcode.com/problems/house-robber/

// BOTTOM UP APPROACH
class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size() - 1;
      vector<int> dp(n+1, -1);

      dp[0] = nums[0];

      for(int i = 1; i <= n; i++) {
        if(i > 1) {
        int pick = nums[i] + dp[i-2];
        int dont_pick = 0 + dp[i-1];
        dp[i] = max(pick, dont_pick);
        }
        else {
          dp[i] = max(nums[i], dp[i-1]);
        }
      }
      return dp[n];
    }
};
