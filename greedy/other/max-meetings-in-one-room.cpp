// https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

class Solution{
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>> vec;
        for(int i = 0; i < N; i++) {
            vec.push_back({S[i], F[i], i+1});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> ans;
        int prev_end_time = -1;
        
        for(int i = 0; i < N; i++) {
            int curr_start_time = vec[i][0];
            int curr_end_time = vec[i][1];
            
            if (curr_start_time > prev_end_time) {
                ans.push_back(vec[i][2]);
                prev_end_time = curr_end_time;
            }
            else continue;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
