// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int capacity = 2;

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));

        return f(0, buy, capacity, prices, dp);
    }
};

// tabulation
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));

      for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
          for(int capacity = 1; capacity <= 2; capacity++) {
            int profit = 0;

            if(buy == 1) {
              int take = -prices[ind] + dp[ind+1][0][capacity]; 
              int dont_take = 0 + dp[ind+1][1][capacity]; 

              profit = max(take, dont_take);
            }
            else {
              int sell = prices[ind] + dp[ind+1][1][capacity-1];
              int dont_sell = 0 + dp[ind+1][0][capacity];

              profit = max(sell, dont_sell);
            }
            
            dp[ind][buy][capacity] = profit;
          }
        }
      }

      return dp[0][1][2];
    }
};
