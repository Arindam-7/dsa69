// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1?

class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({end[i], start[i]});
        }
        
        sort(vec.begin(), vec.end());
        
        int ans = 0;
        int prev_end_time = -1;
        
        for(int i = 0; i < n; i++) {
            int curr_start_time = vec[i].second;
            int curr_end_time = vec[i].first;
            
            if (curr_start_time > prev_end_time) {
                ans++;
                prev_end_time = curr_end_time;
            }
            else continue;
        }
        
        return ans;
    }
};
