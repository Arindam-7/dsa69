// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// memoization
class Solution {
public: 
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
      int profit = 0;
      // base 
      if(ind == prices.size()) return 0;

      if(dp[ind][buy] != -1) return dp[ind][buy];

      if(buy == 1) {
        int take = -prices[ind] + f(ind+1, 0, prices, dp);
        int not_take = 0 + f(ind+1, 1, prices, dp);

        profit = max(take, not_take);
      }
      else {
        int sell = prices[ind] + f(ind+1, 1, prices, dp);
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

// tabulation
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>> dp(n + 1, vector<int> (2, 0));
      
      // base
      dp[n][0] = dp[n][1] = 0;

      for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
          if(buy == 1) {
            dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
          }
          else {
            dp[ind][buy] = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
          }
        }
      }

      return dp[0][1];
    }
};

// space optimization
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> ahead(2, 0);
      vector<int> curr(2, 0);

      // base
      ahead[0] = ahead[1] = 0;

      for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
          if(buy == 1) {
            curr[buy] = max(-prices[ind] + ahead[0], 0 + ahead[1]);
          }
          else {
            curr[buy] = max(prices[ind] + ahead[1], 0 + ahead[0]);
          }
        }

        ahead = curr;
      }

      return ahead[1];
    }
};

