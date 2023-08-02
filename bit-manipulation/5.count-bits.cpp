// https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
  // counts number of 1 in binary representation of n
    int count_setBits(int n) {
        if(n == 0) return 0;
        else return 1 + count_setBits(n & (n-1));
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(count_setBits(i));
        }

        return ans;
    }
};
