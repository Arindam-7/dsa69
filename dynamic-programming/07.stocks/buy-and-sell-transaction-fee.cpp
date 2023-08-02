// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public: 
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee) {
      int profit = 0;
      // base 
      if(ind == prices.size()) return 0;

      if(dp[ind][buy] != -1) return dp[ind][buy];

      if(buy == 1) {
        int take = -prices[ind] + f(ind+1, 0, prices, dp, fee);
        int not_take = 0 + f(ind+1, 1, prices, dp, fee);

        profit = max(take, not_take);
      }
      else {
        int sell = prices[ind] + f(ind+1, 1, prices, dp, fee) - fee;
        int dont_sell = 0 + f(ind+1, 0, prices, dp, fee);

        profit = max(sell, dont_sell);
      }

      return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
       int buy = 1;
       int n = prices.size();
       vector<vector<int>> dp(n, vector<int> (2, -1));

       return f(0, buy, prices, dp, fee);
    }
};

