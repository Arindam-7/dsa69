// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// memoization
class Solution {
public:
    int f(int ind, int buy, int capacity, vector<int>& prices, vector<vector<vector<int>>>& dp) {
      int profit = 0;

      // base 
      if(ind == prices.size()) return 0;
      if(capacity == 0) return 0;

      if(dp[ind][buy][capacity] != -1) return dp[ind][buy][capacity];

      if(buy == 1) {
        int take = -prices[ind] + f(ind+1, 0, capacity, prices, dp);
        int dont_take = 0 + f(ind+1, 1, capacity, prices, dp);

        profit = max(take, dont_take);
      }
      else {
        int sell = prices[ind] + f(ind+1, 1, capacity-1, prices, dp);
        int dont_sell = 0 + f(ind+1, 0, capacity, prices, dp);

        profit = max(sell, dont_sell);
      }

      return dp[ind][buy][capacity] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int capacity = k;

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (capacity + 1, -1)));

        return f(0, buy, capacity, prices, dp);
    }
};

