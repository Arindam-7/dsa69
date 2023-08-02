// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
    public:
    bool checkKthBit(int n, int k)
    {
        int mask = (1<<k);
        return (mask&n);
    }
};
