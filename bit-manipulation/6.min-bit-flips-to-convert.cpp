// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

class Solution {
public:
    int count_set(int n) {
        if(n == 0) return 0;
        else return 1 + count_set(n&(n-1));
    }

    int minBitFlips(int start, int goal) {
        int x = start^goal;
        return count_set(x);
    }
};
