class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      int n = asteroids.size();
      vector<int> ans;
      
      stack<int> st;

      for(auto i : asteroids) {
        if(i > 0 || st.empty()) st.push(i); 

        else {
          while(!st.empty() && st.top() > 0 && abs(i) > st.top()) st.pop();

          if(!st.empty() && abs(i) == st.top()) {
            st.pop();
            continue;
          }

          if(st.empty() || st.top() < 0) st.push(i);
        }
      }

      while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
      }

      reverse(ans.begin(), ans.end());

      return ans;
    }
};
