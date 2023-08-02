// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    bool check_ith_bit_set(int i, int n) {
        int mask = 1 << i;
        return (mask & n);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < (1<<n); i++) {
            vector<int> sub;
            for(int j = 0; j < n; j++) {
                if(check_ith_bit_set(j, i) == true) sub.push_back(nums[j]);
            }

            ans.push_back(sub);
        }

        return ans;
    }
};
