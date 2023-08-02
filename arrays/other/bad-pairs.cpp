// https://leetcode.com/problems/count-number-of-bad-pairs/description/


class Solution {
    typedef long long ll; 
public:
    long long comb(ll n) {
        return n * (n-1) / 2;
    }

    long long countBadPairs(vector<int>& nums) {
        /*
        j - i != nums[j] - nums[i] - to be proved
        or, nums[j] - j != nums[i] - i
        */
        unordered_map<int, int> mp;
        ll n = nums.size();
        if(n == 1) return 0;

        ll badPairs = 0;
        ll goodPairs = 0;
        ll totalPairs = comb(n);

        for(int i = 0; i < n; i++) {
            ll diff = nums[i] - i;
            
            if(mp.count(diff) == 1) {
                goodPairs += mp[diff];
                mp[diff]++;
            }
            else mp[diff] = 1;
        }
        
        // gave TLE
        // for(int i = 0; i < mp.size(); i++) {
        //     if(mp[i] > 1) {
        //         goodPairs += comb(mp[i]);
        //     }
        // }

        badPairs = totalPairs - goodPairs;
        return badPairs;
    }
};
