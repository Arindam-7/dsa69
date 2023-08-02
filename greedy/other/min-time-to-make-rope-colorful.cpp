// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int ans = 0;

        for(int i = 0; i < n-1; i++) {
            int minTime = INT_MAX;
            if(colors[i] == colors[i+1]) {
                // if the current balloon takes lesser time for removal, simply remove it
                if(neededTime[i+1] > neededTime[i]) ans += neededTime[i];
                /*
                if the next balloon takes lesser time, remove the next one(add its time)
                and swap the times
                eg. [4,3] -> [4,4]
                to push the removed balloon backwards, and continue with the prev balloon
                */
                else {
                    ans += neededTime[i+1];
                    swap(neededTime[i], neededTime[i+1]);
                }
            }
        }

        return ans;
    }
};
