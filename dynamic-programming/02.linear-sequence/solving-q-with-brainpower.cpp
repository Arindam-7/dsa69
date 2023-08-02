// https://leetcode.com/problems/solving-questions-with-brainpower/description/


class Solution {
public:
    long long solve(vector<vector<int>>& questions, int index, vector<long long>& dp) {
        if(index >= questions.size()) return 0;

        if(dp[index] != -1) return dp[index];

        long long choice1 = 0, choice2 = 0;
        choice1 = questions[index][0] + solve(questions, (index+questions[index][1]+1), dp);
        choice2 = 0 + solve(questions, index+1, dp);

        dp[index] = max(choice1, choice2);
        return dp[index];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        return solve(questions, 0, dp);
    }
};
