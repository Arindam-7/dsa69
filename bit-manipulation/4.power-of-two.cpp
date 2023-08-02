// https://leetcode.com/problems/power-of-two/description/

// bit
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int check = n&(n-1);
        
        return check == 0 ? true : false;
    }
};
