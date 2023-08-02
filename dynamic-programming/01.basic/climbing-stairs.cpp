// https://leetcode.com/problems/climbing-stairs/

// TOP DOWN APPROACH
class Solution {
public:    
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return count_ways(n, dp);
    }
    
    int count_ways(int n, vector<int> &dp) {
        if(n <= 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = count_ways(n - 1, dp) + count_ways(n - 2, dp);
    }
};


// BOTTOM UP APPROACH
class Solution {
public:    
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp [i - 2];
        }
        
        return dp[n];
    }
};


// SPACE OPTIMISED
class Solution {
public:    
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int prev2 = 1;
        int prev = 1;
        
        for(int i = 2; i <= n; i++) {
            int curri = prev2 + prev;
            prev2 = prev;
            prev = curri;
        }
        
        return prev;
    }
};
