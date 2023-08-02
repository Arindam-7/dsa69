 // https://leetcode.com/problems/partition-equal-subset-sum/description/


// top down
class Solution {
public:
    bool solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp) {
        // base
        if(sum == 0) return true;
        if(ind == 0) return (nums[0] == sum);

        if(dp[ind][sum] != -1) return dp[ind][sum];

        bool not_take = solve(ind-1, sum, nums, dp);
        bool take = false;
        if(sum >= nums[ind]) take = solve(ind-1, sum-nums[ind], nums, dp);

        return dp[ind][sum] = take | not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        vector<vector<int>> dp(n, vector<int> (sum+1, -1));

        if(sum % 2 == 0) return solve(n-1, sum/2, nums, dp);
        else return false;
    }
};


// bottom up 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        if(sum % 2 == 1) return false;
        else {
            int k = sum / 2;
            vector<vector<int>> dp(n, vector<int> (k+1, false));

            // base - if target is 0, index can take any from 0 to n-1
            for(int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
            // base - the first row indicates only the first element is considered
            if(nums[0] <= k) dp[0][nums[0]] = true;

            for(int i = 1; i < n; i++) {
                for(int j = 1; j <= k; j++) {
                  bool notTake = dp[i-1][j];

                   bool take = false;
                    if(nums[i] <= j) {
                        take = dp[i-1][j-nums[i]];
                    }

                    dp[i][j] = take || notTake;
                }
            }

        return dp[n-1][k];
        }
    }
};
