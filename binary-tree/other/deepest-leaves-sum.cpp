// https://leetcode.com/problems/deepest-leaves-sum/description/

// level order traversal

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int ans;

        while(!q.empty()) {
            int s = q.size();

            /* 
            for each level, the sum will be initialised with 0
            thus, in the end, ans will hold the addition of deepest leaves 
            */
            
            ans = 0;

            for(int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();

                ans += temp -> val;

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }

        return ans;
    }
};
