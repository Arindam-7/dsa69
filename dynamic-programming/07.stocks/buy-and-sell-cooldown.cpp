// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public: 
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
      int profit = 0;
      // base 
      if(ind >= prices.size()) return 0;

      if(dp[ind][buy] != -1) return dp[ind][buy];

      if(buy == 1) {
        int take = -prices[ind] + f(ind+1, 0, prices, dp);
        int not_take = 0 + f(ind+1, 1, prices, dp);

        profit = max(take, not_take);
      }
      else {
        int sell = prices[ind] + f(ind+2, 1, prices, dp);
        int dont_sell = 0 + f(ind+1, 0, prices, dp);

        profit = max(sell, dont_sell);
      }

      return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
       int buy = 1;
       int n = prices.size();
       vector<vector<int>> dp(n, vector<int> (2, -1));

       return f(0, buy, prices, dp);
    }
};

