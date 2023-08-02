// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        int i = 0, j = 0;
        int windowSum = 0;

        while(j < n) {
            windowSum += nums[j];
            while(windowSum >= target) {
                windowSum -= nums[i];
                ans = min(ans, j-i+1);
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
