// https://leetcode.com/problems/minimum-cost-for-tickets/description/

// memoization
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
      int n = days.size();

      // base case
      if(index >= n) return 0;

      if(dp[index] != -1) return dp[index];

      int oneDay = costs[0] + solve(days, costs, index+1, dp);
      
      int i = 0;
      for(i = index; i < n && days[i] < days[index]+7; i++);
      int sevenDays = costs[1] + solve(days, costs, i, dp);
      
      int j = 0;
      for(j = index; j < n && days[j] < days[index]+30; j++);
      int thirtyDays = costs[2] + solve(days, costs, j, dp);

      dp[index] = min(oneDay, min(sevenDays, thirtyDays));
      return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int index = 0;
        vector<int> dp(days.size()+1, -1);
        return solve(days, costs, index, dp);
    }
};


// tabulation
class Solution{
  public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      int n = days.size();
      vector<int> dp(n+1, INT_MAX); // INT_MAX because we gotta find minimum cost 

      dp[n] = 0;
    
      for(int k = n-1; k >= 0; k--) {
        int oneDay = costs[0] + dp[k+1];

        int i = 0;
        for(i = k; i < n && days[i] < days[k]+7; i++);
        int sevenDays = costs[1] + dp[i];
      
        int j = 0;
        for(j = k; j < n && days[j] < days[k]+30; j++);
        int thirtyDays = costs[2] + dp[j];

        dp[k] = min(oneDay, min(sevenDays, thirtyDays));
        }

        return dp[0];
      }
};
