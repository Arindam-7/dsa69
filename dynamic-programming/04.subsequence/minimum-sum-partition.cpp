// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


int minDifference(int nums[], int n)  { 
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));

            // base - if target is 0, index can take any from 0 to n-1
            for(int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
            // base - the first row indicates only the first element is considered
            if(nums[0] <= sum) dp[0][nums[0]] = true;

            for(int i = 1; i < n; i++) {
                for(int j = 1; j <= sum; j++) {
                  bool notTake = dp[i-1][j];

                   bool take = false;
                    if(nums[i] <= j) {
                        take = dp[i-1][j-nums[i]];
                    }

                    dp[i][j] = take || notTake;
                }
            }
        
        int mini = INT_MAX;
        for(int s1 = 0; s1 <= sum/2; s1++) {
            if(dp[n-1][s1] == true) mini = min(mini, abs(sum - 2*s1));
        }

        return mini;
	}
