// https://leetcode.com/problems/wildcard-matching/

// memoization
class Solution {
public:
    bool f(int i, int j, string &pattern, string &s, vector<vector<int>> &dp) {
      // base
      if(i < 0 && j < 0) return true;
      if(i < 0 && j >= 0) return false;
      if(j < 0 && i >= 0) {
        for(int k = 0; k <= i; k++) {
          if(pattern[k] != '*') return false;
        }
        return true;
      }

      if(dp[i][j] != -1) return dp[i][j];

      if(pattern[i] == s[j] || pattern[i] == '?') return dp[i][j] = f(i-1, j-1, pattern, s, dp);

      if(pattern[i] == '*') return dp[i][j] = f(i-1, j, pattern, s, dp) or f(i, j-1, pattern, s, dp);

      return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
      int n = p.length(); // length of pattern
      int m = s.length();
        
      vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

      return f(n-1, m-1, p, s, dp);
    }
};

// tabulation
class Solution {
  public:
    bool isMatch(string s, string p) {
      int n = p.length();
      int m = s.length();

      vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));

      // base
      dp[0][0]= true;

      for(int j = 1; j <= m; j++) dp[0][j] = false;

      for(int i = 1; i <= n; i++) {
        bool flag = true;
        for(int k = 1; k <= i; k++) {
          if(p[k-1] != '*') {
            flag = false;
            break;
          }
        }

        dp[i][0] = flag;
      }


      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
          if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];

          else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];

          else dp[i][j] = false;
        }
      }

      return dp[n][m];
    }
};
