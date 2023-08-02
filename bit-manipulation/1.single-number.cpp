// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto i : nums) {
          ans = ans ^ i;
        }

        return ans;
    }
};

