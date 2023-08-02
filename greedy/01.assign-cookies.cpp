class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int children = g.size();
        int cookies = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int a = 0, b = 0;

        while(a < children && b < cookies) {
            if(s[b] >= g[a]) {
                ans++;
                a++;
                b++;
            }
            else b++;
        }

        return ans;
    }
};
