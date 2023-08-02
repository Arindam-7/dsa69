// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(1001, vector<int> (1001));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string inverted_s = s;
        reverse(s.begin(), s.end());
        return longestCommonSubsequence(inverted_s, s);
    }

    int minInsertions(string s) {
        int n = s.length();
        return n - longestPalindromeSubseq(s);
    }
};
